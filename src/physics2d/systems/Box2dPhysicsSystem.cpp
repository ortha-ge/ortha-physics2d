module;

#include <variant>

#include <box2d/box2d.h>
#include <entt/entt.hpp>
#include <glm/glm.hpp>
#include <glm/gtc/quaternion.hpp>

module Physics2d.Box2dPhysicsSystem;

import Core.ProcessError;
import Core.ResourceHandle;
import Core.ResourceHandleUtils;
import Core.Spatial;
import Physics2d.ApplyForceRequest;
import Physics2d.CollisionEvent;
import Physics2d.CollisionShape;
import Physics2d.Rigidbody2d;

namespace Physics2d::Box2dPhysicsSystemInternal {

	struct Box2dRigidbody {
		b2BodyId bodyId{};
	};

	struct Box2dShape {
		b2ShapeId shapeId{};
	};

	b2ShapeId tryCreateCollisionShape(b2BodyId bodyId, b2ShapeDef shapeDef, const Core::Spatial& spatial, const BoxCollisionShape& descriptor) {
		b2Polygon polygon = b2MakeBox(descriptor.width * spatial.scale.x * 0.5f, descriptor.height * spatial.scale.y * 0.5f);
		return b2CreatePolygonShape(bodyId, &shapeDef, &polygon);
	}

	b2ShapeId tryCreateCollisionShape(b2BodyId bodyId, b2ShapeDef shapeDef, const Core::Spatial& spatial, const CircleCollisionShape& descriptor) {
		b2Circle circle{ {}, descriptor.radius };
		return b2CreateCircleShape(bodyId, &shapeDef, &circle);
	}

	void tryCreateCollisionShape(
		entt::registry& registry, const entt::entity entity, b2BodyId bodyId, const Core::Spatial& spatial, const CollisionShape& collisionShape) {
		using namespace Box2dPhysicsSystemInternal;

		std::optional<CollisionShapeDescriptor> collisionShapeDescriptor;
		if (std::holds_alternative<std::shared_ptr<Core::ResourceHandle>>(collisionShape.descriptor)) {
			auto& resourceHandle = std::get<std::shared_ptr<Core::ResourceHandle>>(collisionShape.descriptor);
			auto&& [collisionShapeResourceEntity, collisionShapeResource] = Core::getResourceAndEntity<CollisionShapeDescriptor>(registry, resourceHandle);
			if (!collisionShapeResource) {
				Core::addProcessError(registry, entity, !Core::hasHaltedProcessError(registry, collisionShapeResourceEntity));
				return;
			}

			collisionShapeDescriptor = *collisionShapeResource;
		} else if (std::holds_alternative<CollisionShapeDescriptor>(collisionShape.descriptor)) {
			collisionShapeDescriptor = std::get<CollisionShapeDescriptor>(collisionShape.descriptor);
		}

		if (!collisionShapeDescriptor) {
			return;
		}

		b2ShapeDef shapeDef = b2DefaultShapeDef();
		shapeDef.userData = reinterpret_cast<void*>(static_cast<uintptr_t>(entity));
		shapeDef.enableHitEvents = true;
		shapeDef.enableContactEvents = true;

		b2ShapeId shapeId = std::visit([bodyId, shapeDef = std::move(shapeDef), &spatial](auto&& descriptor) {
			return tryCreateCollisionShape(bodyId, std::move(shapeDef), spatial, descriptor);
		}, *collisionShapeDescriptor);

		if (!b2Shape_IsValid(shapeId)) {
			Core::addProcessError(registry, entity, "Failed to create box2d shape.");
			return;
		}

		registry.emplace<Box2dShape>(entity, shapeId);
	}

	void destroyRigidbody(entt::registry& registry, const entt::entity entity) {
		if (!registry.all_of<Box2dRigidbody>(entity)) {
			return;
		}

		Box2dRigidbody& rigidBody = registry.get<Box2dRigidbody>(entity);
		if (!b2Body_IsValid(rigidBody.bodyId)) {
			return;
		}

		b2DestroyBody(rigidBody.bodyId);
	}

	void destroyCollisionShape(entt::registry& registry, const entt::entity entity) {
		if (!registry.all_of<Box2dShape>(entity)) {
			return;
		}

		Box2dShape& shape = registry.get<Box2dShape>(entity);
		if (!b2Shape_IsValid(shape.shapeId)) {
			return;
		}

		b2DestroyShape(shape.shapeId, true);
	}

	void applyForce(const Box2dRigidbody& box2dRigidBody, const ApplyForceRequest& applyForceRequest) {
		if (!b2Body_IsValid(box2dRigidBody.bodyId)) {
			return;
		}

		b2Vec2 force{ applyForceRequest.force.x, applyForceRequest.force.y };
		b2Vec2 center{ b2Body_GetWorldCenterOfMass(box2dRigidBody.bodyId) };
		center.x += applyForceRequest.center.x;
		center.y += applyForceRequest.center.y;

		switch (applyForceRequest.type) {
			case ForceType::Force:
				b2Body_ApplyForce(box2dRigidBody.bodyId, std::move(force), std::move(center), true);
				break;
			case ForceType::Impulse:
				b2Body_ApplyLinearImpulse(box2dRigidBody.bodyId, std::move(force), std::move(center), true);
				break;
		}
	}

	void connectCallbacks(entt::registry& registry) {
		registry.on_destroy<Box2dRigidbody>()
			.connect<&destroyRigidbody>();

		registry.on_destroy<Box2dShape>()
			.connect<&destroyCollisionShape>();
	}

	void disconnectCallbacks(entt::registry& registry) {
		registry.on_destroy<Box2dRigidbody>()
			.disconnect<&destroyRigidbody>();

		registry.on_destroy<Box2dShape>()
			.disconnect<&destroyCollisionShape>();
	}

} // namespace Physics2d::Box2dPhysicsSystemInternal

namespace Physics2d {

	Box2dPhysicsSystem::Box2dPhysicsSystem(Core::EnTTRegistry& _registry, Core::Scheduler& scheduler, const Core::Timer& timer)
		: mRegistry{ _registry }
		, mScheduler{ scheduler }
		, mTimer{ timer } {

		using namespace Box2dPhysicsSystemInternal;

		b2WorldDef worldDef = b2DefaultWorldDef();
		worldDef.gravity = b2Vec2{ 0.0f, 10.0f };

		mWorld = b2CreateWorld(&worldDef);

		mTickHandle = mScheduler.schedule([this] {
			tickSystem(mRegistry, mTimer);
		});

		connectCallbacks(mRegistry);
	}

	Box2dPhysicsSystem::~Box2dPhysicsSystem() {
		using namespace Box2dPhysicsSystemInternal;

		disconnectCallbacks(mRegistry);

		mScheduler.unschedule(std::move(mTickHandle));

		b2DestroyWorld(mWorld);
		mWorld = {};
	}

	void Box2dPhysicsSystem::tickSystem(entt::registry& registry, const Core::Timer& timer) {
		using namespace Box2dPhysicsSystemInternal;

		registry.view<Rigidbody, Core::Spatial>(entt::exclude<Box2dRigidbody, Core::ProcessError>)
			.each([this, &registry](const entt::entity entity, const Rigidbody& rigidbody, const Core::Spatial& spatial) {
				tryCreateRigidbody(registry, entity, mWorld, rigidbody, spatial);
			});

		registry.view<Box2dRigidbody, Core::Spatial, CollisionShape>(entt::exclude<Box2dShape, Core::ProcessError>)
			.each([this, &registry](
					  const entt::entity entity, const Box2dRigidbody& rigidbody, const Core::Spatial& spatial,
					  const CollisionShape& collisionShape) {
				tryCreateCollisionShape(registry, entity, rigidbody.bodyId, spatial, collisionShape);
			});

		registry.view<Box2dRigidbody, ApplyForceRequest>()
			.each([&registry](const Box2dRigidbody& rigidBody, const ApplyForceRequest& applyForceRequest) {
				applyForce(rigidBody, applyForceRequest);
			});

		registry.clear<ApplyForceRequest>();

		registry.view<CollisionEvent>()
			.each([&registry](const entt::entity entity, const CollisionEvent& collisionEvent) {
				registry.destroy(entity);
			});

		constexpr float timeStep = 1.0f / 60.0f;
		constexpr int subStepCount = 4;

		float accumulatedTime = 0.0f;
		size_t physicsTicks = 0;
		while (accumulatedTime < timer.getDeltaT()) {
			b2World_Step(mWorld, timeStep, subStepCount);
			accumulatedTime += timeStep;
			++physicsTicks;
		}

		registry.view<Box2dRigidbody, Core::Spatial>()
			.each([](const Box2dRigidbody& box2dRigidbody, Core::Spatial& spatial) {
				const b2Vec2 position{ b2Body_GetPosition(box2dRigidbody.bodyId) };
				spatial.position.x = position.x;
				spatial.position.y = position.y;

				const b2Rot rotation{ b2Body_GetRotation(box2dRigidbody.bodyId) };
				const float angle{ b2Rot_GetAngle(rotation) };
				spatial.rotation = glm::angleAxis(angle, glm::vec3(0.0f, 0.0f, 1.0f));
			});

		registry.view<Box2dRigidbody, Rigidbody>()
			.each([](const Box2dRigidbody& box2dRigidBody, Rigidbody& rigidBody) {
				rigidBody.isOnGround = false;

				b2ContactData contactData[8];
				int contactCount = b2Body_GetContactData(box2dRigidBody.bodyId, contactData, 8);
				for (int i = 0; i < contactCount; ++i) {
					const auto& contact{ contactData[i] };
					const b2BodyId bodyIdA = b2Shape_GetBody(contact.shapeIdA);
					const b2BodyId bodyIdB = b2Shape_GetBody(contact.shapeIdB);
					const b2Vec2 bodyPosA = b2Body_GetPosition(bodyIdA);
					const b2Vec2 bodyPosB = b2Body_GetPosition(bodyIdB);


					if (B2_ID_EQUALS(box2dRigidBody.bodyId, bodyIdA) && bodyPosA.y < bodyPosB.y) {
						rigidBody.isOnGround = true;
					} else if (B2_ID_EQUALS(box2dRigidBody.bodyId, bodyIdB) && bodyPosB.y < bodyPosA.y) {
						rigidBody.isOnGround = true;
					}
				}
			});

		b2ContactEvents contactEvents = b2World_GetContactEvents(mWorld);
		for (int i = 0; i < contactEvents.hitCount; ++i) {
			const entt::entity collisionEntity{ registry.create() };
			const auto& hitEvent{ contactEvents.hitEvents[i] };
			const auto entityA = static_cast<entt::entity>(reinterpret_cast<uintptr_t>(b2Shape_GetUserData(hitEvent.shapeIdA)));
			const auto entityB = static_cast<entt::entity>(reinterpret_cast<uintptr_t>(b2Shape_GetUserData(hitEvent.shapeIdB)));
			registry.emplace<CollisionEvent>(collisionEntity, entityA, entityB);
		}
	}

	void Box2dPhysicsSystem::tryCreateRigidbody(
		entt::registry& registry, const entt::entity entity, b2WorldId world, const Rigidbody& rigidbody,
		const Core::Spatial& spatial) {
		using namespace Box2dPhysicsSystemInternal;

		b2BodyDef bodyDef = b2DefaultBodyDef();
		bodyDef.type = rigidbody.isStatic ? b2_staticBody : b2_dynamicBody;
		bodyDef.position = b2Vec2{ spatial.position.x, spatial.position.y };

		b2BodyId bodyId{ b2CreateBody(world, &bodyDef) };
		if (!b2Body_IsValid(bodyId)) {
			Core::addProcessError(registry, entity, "Failed to create box2d rigidbody.");
			return;
		}

		registry.emplace<Box2dRigidbody>(entity, bodyId);
	}

} // namespace Physics2d
