export module Ortha.Physics2d.Reflection.BoxCollisionShape;

export import Ortha.Physics2d.BoxCollisionShape;

import Ortha.RTTI.ReflectionContext;

namespace Ortha::RTTI {

	template<>
	void reflect<Physics2d::BoxCollisionShape>(ReflectionContext& reflectionContext) {
		using namespace Physics2d;
		reflectionContext.addClass<BoxCollisionShape>("BoxCollisionShape")
			.field<&BoxCollisionShape::width>("width")
			.field<&BoxCollisionShape::height>("height")
		;
	}

}
