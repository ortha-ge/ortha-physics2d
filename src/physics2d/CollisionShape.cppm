module;

#include <variant>

export module Physics2d.CollisionShape;

export namespace Physics2d {

	struct BoxCollisionShapeDescriptor {
		float width{ 1.0f };
		float height { 1.0f };
	};

	using CollisionShapeDescriptor = std::variant<BoxCollisionShapeDescriptor>;

	struct CollisionShape {
		CollisionShapeDescriptor descriptor;
	};

} // namespace Physics2d
