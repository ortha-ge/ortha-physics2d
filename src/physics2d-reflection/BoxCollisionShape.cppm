export module Physics2d.Reflection.BoxCollisionShape;

export import Physics2d.BoxCollisionShape;

import Core.ReflectionContext;

template<>
void Core::reflect<Physics2d::BoxCollisionShape>(ReflectionContext& reflectionContext) {
	using namespace Physics2d;
	reflectionContext.addClass<BoxCollisionShape>("BoxCollisionShape")
		.property("width", &BoxCollisionShape::width)
		.property("height", &BoxCollisionShape::height)
	.build();
}
