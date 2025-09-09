module;

#include <variant>

export module Physics2d.CollisionShape;

export namespace Physics2d {

	struct BoxCollisionShapeDescriptor {
		float width{ 1.0f };
		float height { 1.0f };
	};

	struct CircleCollisionShapeDescriptor {
		float radius { 1.0f };
	};

	using CollisionShapeDescriptor = std::variant<BoxCollisionShapeDescriptor, CircleCollisionShapeDescriptor>;

	struct CollisionShape {
		CollisionShapeDescriptor descriptor;
	};

} // namespace Physics2d
