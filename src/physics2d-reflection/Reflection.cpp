module Physics2d.Reflection;

import Core.Reflect;
import Ortha.RTTI.ReflectionContext;

namespace Physics2d {

	void reflectAll(Ortha::RTTI::ReflectionContext& reflectionContext) {
		using namespace Core;

		reflect<BoxCollisionShape>(reflectionContext);
		reflect<CircleCollisionShape>(reflectionContext);
		reflect<CollisionShape>(reflectionContext);
		reflect<Rigidbody>(reflectionContext);
	}

} // namespace Physics2d
