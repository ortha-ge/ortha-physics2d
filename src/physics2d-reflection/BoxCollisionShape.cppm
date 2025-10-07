export module Ortha.Physics2d.Reflection.BoxCollisionShape;

export import Ortha.Physics2d.BoxCollisionShape;

import Ortha.Core.Reflect;

template<>
void Core::reflect<Ortha::Physics2d::BoxCollisionShape>(Ortha::RTTI::ReflectionContext& reflectionContext) {
	using namespace Ortha::Physics2d;
	reflectionContext.addClass<BoxCollisionShape>("BoxCollisionShape")
		.field<&BoxCollisionShape::width>("width")
		.field<&BoxCollisionShape::height>("height")
	;
}
