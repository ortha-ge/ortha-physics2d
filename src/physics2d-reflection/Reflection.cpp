module Physics2d.Reflection;

import Core.ReflectionContext;

namespace Physics2d {

	void reflectAll(Core::ReflectionContext& reflectionContext) {
		using namespace Core;

		reflect<BoxCollisionShape>(reflectionContext);
		reflect<CircleCollisionShape>(reflectionContext);
		reflect<CollisionShape>(reflectionContext);
		reflect<Rigidbody>(reflectionContext);
	}

} // namespace Physics2d
