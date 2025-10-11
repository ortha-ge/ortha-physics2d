export module Ortha.Physics2d.Reflection.Rigidbody2d;

export import Ortha.Physics2d.Rigidbody2d;

import Ortha.Core.EnTTComponentAttribute;
import Ortha.RTTI.ReflectionContext;

namespace Ortha::RTTI {

	template<>
	void reflect<Physics2d::Rigidbody>(ReflectionContext& reflectionContext) {
		using namespace Physics2d;
		reflectionContext.addClass<Rigidbody>("Rigidbody2d")
			.field<&Rigidbody::isStatic>("isStatic")
			//.annotate(createEnTTComponentAttribute<Rigidbody>())
		;
	}

}
