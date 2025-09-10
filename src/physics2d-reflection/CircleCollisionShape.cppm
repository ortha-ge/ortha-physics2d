export module Physics2d.Reflection.CircleCollisionShape;

export import Physics2d.CircleCollisionShape;

import Core.ReflectionContext;

template<>
void Core::reflect<Physics2d::CircleCollisionShape>(ReflectionContext& reflectionContext) {
	using namespace Physics2d;
	reflectionContext.addClass<CircleCollisionShape>("CircleCollisionShape")
		.property("radius", &CircleCollisionShape::radius)
	.build();
}
