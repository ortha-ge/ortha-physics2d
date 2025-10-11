export module Ortha.Physics2d.Reflection.CircleCollisionShape;

export import Ortha.Physics2d.CircleCollisionShape;

import Ortha.RTTI.ReflectionContext;

namespace Ortha::RTTI {

	template<>
	void reflect<Physics2d::CircleCollisionShape>(ReflectionContext& reflectionContext) {
		using namespace Physics2d;
		reflectionContext.addClass<CircleCollisionShape>("CircleCollisionShape")
			.field<&CircleCollisionShape::radius>("radius")
		;
	}

}
