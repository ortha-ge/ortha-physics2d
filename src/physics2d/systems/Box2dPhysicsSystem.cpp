module;

#include <variant>

#include <box2d/box2d.h>
#include <entt/entt.hpp>

module Physics2d.Box2dPhysicsSystem;

import Core.ProcessError;
import Core.Spatial;
import Physics2d.CollisionShape;
import Physics2d.Rigidbody2d;

namespace Physics2d::Box2dPhysicsSystemInternal {

	struct Box2dRigidbody {
		b2BodyId bodyId{};
	};

	struct Box2dShape {
		b2ShapeId shapeId{};
	};

	b2ShapeId tryCreateCollisionShape(b2BodyId bodyId, b2ShapeDef shapeDef, const Core::Spatial& spatial, const BoxCollisionShapeDescriptor& descriptor) {
		b2Polygon polygon = b2MakeBox(descriptor.width * spatial.scaleX * 0.5f, descriptor.height * spatial.scaleY * 0.5f);
		return b2CreatePolygonShape(bodyId, &shapeDef, &polygon);
	}

	void tryCreateCollisionShape(
		entt::registry& registry, const entt::entity entity, b2BodyId bodyId, const Core::Spatial& spatial, const CollisionShape& collisionShape) {
		using namespace Box2dPhysicsSystemInternal;

		b2ShapeDef shapeDef = b2DefaultShapeDef();
		b2ShapeId shapeId = std::visit([bodyId, shapeDef = std::move(shapeDef), &spatial](auto&& descriptor) {
			return tryCreateCollisionShape(bodyId, std::move(shapeDef), spatial, descriptor);
		}, collisionShape.descriptor);

		if (!b2Shape_IsValid(shapeId)) {
			Core::addProcessError(registry, entity, "Failed to create box2d shape.");
			return;
		}

		registry.emplace<Box2dShape>(entity, shapeId);
	}

} // namespace Physics2d::Box2dPhysicsSystemInternal

namespace Physics2d {

	Box2dPhysicsSystem::Box2dPhysicsSystem(Core::EnTTRegistry& registry, Core::Scheduler& scheduler)
		: mRegistry{ registry }
		, mScheduler{ scheduler } {

		b2WorldDef worldDef = b2DefaultWorldDef();
		worldDef.gravity = b2Vec2{ 0.0f, 10.0f };

		mWorld = b2CreateWorld(&worldDef);

		mTickHandle = mScheduler.schedule([this] {
			tickSystem(mRegistry);
		});
	}

	Box2dPhysicsSystem::~Box2dPhysicsSystem() {
		mScheduler.unschedule(std::move(mTickHandle));

		b2DestroyWorld(mWorld);
		mWorld = {};
	}

	void Box2dPhysicsSystem::tickSystem(entt::registry& registry) {
		using namespace Box2dPhysicsSystemInternal;
		constexpr float timeStep = 1.0f / 60.0f;
		constexpr int subStepCount = 4;

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

		b2World_Step(mWorld, timeStep, subStepCount);

		registry.view<Box2dRigidbody, Core::Spatial>()
			.each([](const Box2dRigidbody& box2dRigidbody, Core::Spatial& spatial) {
				const b2Vec2 position{ b2Body_GetPosition(box2dRigidbody.bodyId) };
				spatial.x = position.x;
				spatial.y = position.y;
			});
	}

	void Box2dPhysicsSystem::tryCreateRigidbody(
		entt::registry& registry, const entt::entity entity, b2WorldId world, const Rigidbody& rigidbody,
		const Core::Spatial& spatial) {
		using namespace Box2dPhysicsSystemInternal;

		b2BodyDef bodyDef = b2DefaultBodyDef();
		bodyDef.type = rigidbody.isStatic ? b2_staticBody : b2_dynamicBody;
		bodyDef.position = b2Vec2{ spatial.x, spatial.y };

		b2BodyId bodyId{ b2CreateBody(world, &bodyDef) };
		if (!b2Body_IsValid(bodyId)) {
			Core::addProcessError(registry, entity, "Failed to create box2d rigidbody.");
			return;
		}

		registry.emplace<Box2dRigidbody>(entity, bodyId);
	}

} // namespace Physics2d
