export module Ortha.Physics2d.Reflection.Rigidbody2d;

export import Ortha.Physics2d.Rigidbody2d;

import Ortha.Core.EnTTComponentAttribute;
import Ortha.Core.Reflect;

template<>
void Core::reflect<Ortha::Physics2d::Rigidbody>(Ortha::RTTI::ReflectionContext& reflectionContext) {
	using namespace Ortha::Physics2d;
	reflectionContext.addClass<Rigidbody>("Rigidbody2d")
		.field<&Rigidbody::isStatic>("isStatic")
		//.annotate(createEnTTComponentAttribute<Rigidbody>())
	;
}
