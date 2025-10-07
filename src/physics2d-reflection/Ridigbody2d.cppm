export module Physics2d.Reflection.Rigidbody2d;

export import Physics2d.Rigidbody2d;

import Core.EnTTComponentAttribute;
import Core.Reflect;

template<>
void Core::reflect<Physics2d::Rigidbody>(Ortha::RTTI::ReflectionContext& reflectionContext) {
	using namespace Physics2d;
	reflectionContext.addClass<Rigidbody>("Rigidbody2d")
		.field<&Rigidbody::isStatic>("isStatic")
		//.annotate(createEnTTComponentAttribute<Rigidbody>())
	;
}
