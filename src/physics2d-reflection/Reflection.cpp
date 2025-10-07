module Ortha.Physics2d.Reflection;

import Ortha.Core.Reflect;
import Ortha.RTTI.ReflectionContext;

namespace Ortha::Physics2d {

	void reflectAll(Ortha::RTTI::ReflectionContext& reflectionContext) {
		using namespace Core;

		reflect<BoxCollisionShape>(reflectionContext);
		reflect<CircleCollisionShape>(reflectionContext);
		reflect<CollisionShape>(reflectionContext);
		reflect<Rigidbody>(reflectionContext);
	}

} // namespace Ortha::Physics2d
