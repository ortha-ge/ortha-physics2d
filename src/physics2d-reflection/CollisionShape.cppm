export module Ortha.Physics2d.Reflection.CollisionShape;

export import Ortha.Physics2d.CollisionShape;

import Ortha.Core.EnTTComponentAttribute;
import Ortha.Core.Reflect;

namespace Ortha::Core {

	template <>
	void reflect<Physics2d::CollisionShape>(RTTI::ReflectionContext& reflectionContext) {
		using namespace Physics2d;

		reflectionContext.addClass<CollisionShape>("CollisionShape")
			//.annotate(createEnTTComponentAttribute<CollisionShape>())
			;
	}

}
