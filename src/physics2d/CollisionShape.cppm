module;

#include <memory>
#include <variant>

export module Ortha.Physics2d.CollisionShape;

export import Ortha.Physics2d.BoxCollisionShape;
export import Ortha.Physics2d.CircleCollisionShape;

import Ortha.Core.ResourceHandle;

export namespace Ortha::Physics2d {

	using CollisionShapeDescriptor = std::variant<BoxCollisionShape, CircleCollisionShape>;

	struct CollisionShape {
		std::variant<CollisionShapeDescriptor, std::shared_ptr<Core::ResourceHandle>> descriptor;
	};

} // namespace Ortha::Physics2d
