module;

#include <box2d/id.h>

export module Ortha.Physics2d.Box2dPhysicsSystem;

import Ortha.Core.Scheduler;
import Ortha.Core.Spatial;
import Ortha.Core.Timer;
import Ortha.Physics2d.CollisionShape;
import Ortha.Physics2d.Rigidbody2d;
import entt;

export namespace Ortha::Physics2d {

	class Box2dPhysicsSystem {
	public:

		Box2dPhysicsSystem(entt::registry&, Core::Scheduler&, const Core::Timer&);
		~Box2dPhysicsSystem();

		void tickSystem(entt::registry&, const Core::Timer&);
		static void tryCreateRigidbody(entt::registry&, entt::entity, b2WorldId, const Rigidbody&, const Core::Spatial&);

	private:

		entt::registry& mRegistry;
		Core::Scheduler& mScheduler;
		const Core::Timer& mTimer;
		Core::TaskHandle mTickHandle;

		b2WorldId mWorld{};
		float mAccumulatedDeltaT{};

	};

} // namespace Ortha::Physics2d
