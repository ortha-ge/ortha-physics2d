export module Ortha.Physics2d.Systems;

import Ortha.Core.Scheduler;
import Ortha.Core.Timer;
import entt;

export namespace Ortha::Physics2d {

	class Physics2dSystems {
	public:

		Physics2dSystems(entt::registry&, Core::Scheduler&, Core::Timer&);
		~Physics2dSystems();

		void tickSystem(entt::registry&);

	private:

		entt::registry& mRegistry;
		Core::Scheduler& mScheduler;
		Core::TaskHandle mTickHandle;

	};

} // namespace Ortha::Physics2d
