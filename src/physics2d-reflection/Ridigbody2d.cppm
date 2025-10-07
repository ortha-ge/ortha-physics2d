export module Ortha.Physics2d.Reflection.Rigidbody2d;

export import Ortha.Physics2d.Rigidbody2d;

import Ortha.Core.EnTTComponentAttribute;
import Ortha.Core.Reflect;

namespace Ortha::Core {

	template<>
	void reflect<Physics2d::Rigidbody>(RTTI::ReflectionContext& reflectionContext) {
		using namespace Physics2d;
		reflectionContext.addClass<Rigidbody>("Rigidbody2d")
			.field<&Rigidbody::isStatic>("isStatic")
			//.annotate(createEnTTComponentAttribute<Rigidbody>())
		;
	}

}
