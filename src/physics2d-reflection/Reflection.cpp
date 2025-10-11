module Ortha.Physics2d.Reflection;

import Ortha.RTTI.Reflect;
import Ortha.RTTI.ReflectionContext;

namespace Ortha::Physics2d {

	void reflectAll(RTTI::ReflectionContext& reflectionContext) {
		using namespace Ortha::RTTI;

		reflect<BoxCollisionShape>(reflectionContext);
		reflect<CircleCollisionShape>(reflectionContext);
		reflect<CollisionShape>(reflectionContext);
		reflect<Rigidbody>(reflectionContext);
	}

} // namespace Ortha::Physics2d
