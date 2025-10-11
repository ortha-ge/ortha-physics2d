export module Ortha.Physics2d.Reflection.CollisionShape;

export import Ortha.Physics2d.CollisionShape;

import Ortha.Core.EnTTComponentAttribute;
import Ortha.RTTI.ReflectionContext;

namespace Ortha::RTTI {

	template <>
	void reflect<Physics2d::CollisionShape>(ReflectionContext& reflectionContext) {
		using namespace Physics2d;

		reflectionContext.addClass<CollisionShape>("CollisionShape")
			//.annotate(createEnTTComponentAttribute<CollisionShape>())
			;
	}

}
