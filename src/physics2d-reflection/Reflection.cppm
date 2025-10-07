export module Ortha.Physics2d.Reflection;

export import Ortha.Physics2d.Reflection.BoxCollisionShape;
export import Ortha.Physics2d.Reflection.CircleCollisionShape;
export import Ortha.Physics2d.Reflection.CollisionShape;
export import Ortha.Physics2d.Reflection.Rigidbody2d;

import Ortha.RTTI.ReflectionContext;

export namespace Ortha::Physics2d {

	void reflectAll(Ortha::RTTI::ReflectionContext&);

} // namespace Ortha::Physics2d
