export module Ortha.Physics2d.Reflection.CollisionShape;

export import Ortha.Physics2d.CollisionShape;

import Ortha.Core.EnTTComponentAttribute;
import Ortha.Core.Reflect;

template <>
void Core::reflect<Ortha::Physics2d::CollisionShape>(Ortha::RTTI::ReflectionContext& reflectionContext) {
	using namespace Ortha::Physics2d;

	reflectionContext.addClass<CollisionShape>("CollisionShape")
		//.annotate(createEnTTComponentAttribute<CollisionShape>())
		;
}
