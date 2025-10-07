export module Ortha.Physics2d.Reflection.CircleCollisionShape;

export import Ortha.Physics2d.CircleCollisionShape;

import Ortha.Core.Reflect;

template<>
void Core::reflect<Ortha::Physics2d::CircleCollisionShape>(Ortha::RTTI::ReflectionContext& reflectionContext) {
	using namespace Ortha::Physics2d;
	reflectionContext.addClass<CircleCollisionShape>("CircleCollisionShape")
		.field<&CircleCollisionShape::radius>("radius")
	;
}
