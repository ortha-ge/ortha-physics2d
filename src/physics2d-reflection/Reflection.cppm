export module Physics2d.Reflection;

export import Physics2d.Reflection.BoxCollisionShape;
export import Physics2d.Reflection.CircleCollisionShape;
export import Physics2d.Reflection.CollisionShape;
export import Physics2d.Reflection.Rigidbody2d;

import Ortha.RTTI.ReflectionContext;

export namespace Physics2d {

	void reflectAll(Ortha::RTTI::ReflectionContext&);

} // namespace Physics2d
