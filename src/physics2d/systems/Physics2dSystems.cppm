export module Physics2d.Systems;

import Core.Scheduler;
import Core.Timer;
import entt;

export namespace Physics2d {

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

} // namespace Physics2d
