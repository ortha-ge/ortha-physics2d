export module Ortha.Physics2d.Reflection.CircleCollisionShape;

export import Ortha.Physics2d.CircleCollisionShape;

import Ortha.Core.Reflect;

namespace Ortha::Core {

	template<>
	void reflect<Physics2d::CircleCollisionShape>(RTTI::ReflectionContext& reflectionContext) {
		using namespace Physics2d;
		reflectionContext.addClass<CircleCollisionShape>("CircleCollisionShape")
			.field<&CircleCollisionShape::radius>("radius")
		;
	}

}
