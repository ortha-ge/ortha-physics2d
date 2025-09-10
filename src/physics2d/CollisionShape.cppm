module;

#include <memory>
#include <variant>

export module Physics2d.CollisionShape;

export import Physics2d.BoxCollisionShape;
export import Physics2d.CircleCollisionShape;

import Core.ResourceHandle;

export namespace Physics2d {

	using CollisionShapeDescriptor = std::variant<BoxCollisionShape, CircleCollisionShape>;

	struct CollisionShape {
		std::variant<CollisionShapeDescriptor, std::shared_ptr<Core::ResourceHandle>> descriptor;
	};

} // namespace Physics2d
