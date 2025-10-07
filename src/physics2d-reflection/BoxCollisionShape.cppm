export module Ortha.Physics2d.Reflection.BoxCollisionShape;

export import Ortha.Physics2d.BoxCollisionShape;

import Ortha.Core.Reflect;

namespace Ortha::Core {

	template<>
	void reflect<Physics2d::BoxCollisionShape>(RTTI::ReflectionContext& reflectionContext) {
		using namespace Physics2d;
		reflectionContext.addClass<BoxCollisionShape>("BoxCollisionShape")
			.field<&BoxCollisionShape::width>("width")
			.field<&BoxCollisionShape::height>("height")
		;
	}

}
