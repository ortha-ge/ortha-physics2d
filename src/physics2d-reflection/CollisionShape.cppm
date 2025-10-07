export module Physics2d.Reflection.CollisionShape;

export import Physics2d.CollisionShape;

import Core.EnTTComponentAttribute;
import Core.Reflect;

template <>
void Core::reflect<Physics2d::CollisionShape>(Ortha::RTTI::ReflectionContext& reflectionContext) {
	using namespace Physics2d;

	reflectionContext.addClass<CollisionShape>("CollisionShape")
		//.annotate(createEnTTComponentAttribute<CollisionShape>())
		;
}
