export module Physics2d.Reflection;

export import Physics2d.Reflection.BoxCollisionShape;
export import Physics2d.Reflection.CircleCollisionShape;
export import Physics2d.Reflection.CollisionShape;
export import Physics2d.Reflection.Rigidbody2d;

import Core.ReflectionContext;

export namespace Physics2d {

	void reflectAll(Core::ReflectionContext&);

} // namespace Physics2d
