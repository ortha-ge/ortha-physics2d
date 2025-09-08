module;

#include <box2d/id.h>
#include <entt/fwd.hpp>

export module Physics2d.Box2dPhysicsSystem;

import Core.EnTTRegistry;
import Core.Scheduler;
import Core.Spatial;
import Physics2d.CollisionShape;
import Physics2d.Rigidbody2d;

export namespace Physics2d {

	class Box2dPhysicsSystem {
	public:

		Box2dPhysicsSystem(Core::EnTTRegistry&, Core::Scheduler&);
		~Box2dPhysicsSystem();

		void tickSystem(entt::registry&);
		static void tryCreateRigidbody(entt::registry&, entt::entity, b2WorldId, const Rigidbody&, const Core::Spatial&);

	private:

		Core::EnTTRegistry& mRegistry;
		Core::Scheduler& mScheduler;
		Core::TaskHandle mTickHandle;

		b2WorldId mWorld{};

	};

} // namespace Physics2d
