module;

#include <entt/fwd.hpp>

export module Physics2d.Systems;

import Core.EnTTRegistry;
import Core.Scheduler;
import Core.Timer;
import Physics2d.Box2dPhysicsSystem;

export namespace Physics2d {

	class Physics2dSystems {
	public:

		Physics2dSystems(Core::EnTTRegistry&, Core::Scheduler&, Core::Timer&);
		~Physics2dSystems();

		void tickSystem(entt::registry&);

	private:

		Core::EnTTRegistry& mRegistry;
		Core::Scheduler& mScheduler;
		Core::TaskHandle mTickHandle;
		Box2dPhysicsSystem mBox2dPhysicsSystem;

	};

} // namespace Physics2d
