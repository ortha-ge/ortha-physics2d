export module Physics2d.Reflection.Rigidbody2d;

export import Physics2d.Rigidbody2d;

import Core.EnTTComponentAttribute;
import Core.ReflectionContext;

template<>
void Core::reflect<Physics2d::Rigidbody>(ReflectionContext& reflectionContext) {
	using namespace Physics2d;
	reflectionContext.addClass<Rigidbody>("Rigidbody2d")
		.property("isStatic", &Rigidbody::isStatic)
		.annotate(createEnTTComponentAttribute<Rigidbody>())
	.build();
}
