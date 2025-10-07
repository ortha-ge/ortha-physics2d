export module Physics2d.Reflection.CircleCollisionShape;

export import Physics2d.CircleCollisionShape;

import Core.Reflect;

template<>
void Core::reflect<Physics2d::CircleCollisionShape>(Ortha::RTTI::ReflectionContext& reflectionContext) {
	using namespace Physics2d;
	reflectionContext.addClass<CircleCollisionShape>("CircleCollisionShape")
		.field<&CircleCollisionShape::radius>("radius")
	;
}
