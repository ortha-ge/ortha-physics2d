export module Physics2d.Reflection.CollisionShape;

export import Physics2d.CollisionShape;

import Core.EnTTComponentAttribute;
import Core.ReflectionContext;

template <>
void Core::reflect<Physics2d::CollisionShape>(ReflectionContext& reflectionContext) {
	using namespace Physics2d;

	reflectionContext.addClass<CollisionShape>("CollisionShape")
		.annotate(createEnTTComponentAttribute<CollisionShape>())
		.build();
}
