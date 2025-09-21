module;

#include <box2d/id.h>
#include <entt/fwd.hpp>

export module Physics2d.Box2dPhysicsSystem;

import Core.EnTTRegistry;
import Core.Scheduler;
import Core.Spatial;
import Core.Timer;
import Physics2d.CollisionShape;
import Physics2d.Rigidbody2d;

export namespace Physics2d {

	class Box2dPhysicsSystem {
	public:

		Box2dPhysicsSystem(Core::EnTTRegistry&, Core::Scheduler&, const Core::Timer&);
		~Box2dPhysicsSystem();

		void tickSystem(entt::registry&, const Core::Timer&);
		static void tryCreateRigidbody(entt::registry&, entt::entity, b2WorldId, const Rigidbody&, const Core::Spatial&);

	private:

		Core::EnTTRegistry& mRegistry;
		Core::Scheduler& mScheduler;
		const Core::Timer& mTimer;
		Core::TaskHandle mTickHandle;

		b2WorldId mWorld{};
		float mAccumulatedDeltaT{};

	};

} // namespace Physics2d
