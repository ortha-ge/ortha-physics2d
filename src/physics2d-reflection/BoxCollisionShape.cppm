export module Physics2d.Reflection.BoxCollisionShape;

export import Physics2d.BoxCollisionShape;

import Core.Reflect;

template<>
void Core::reflect<Physics2d::BoxCollisionShape>(Ortha::RTTI::ReflectionContext& reflectionContext) {
	using namespace Physics2d;
	reflectionContext.addClass<BoxCollisionShape>("BoxCollisionShape")
		.field<&BoxCollisionShape::width>("width")
		.field<&BoxCollisionShape::height>("height")
	;
}
