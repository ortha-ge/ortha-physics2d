
export module Physics2d.SystemsService;

import Core.EnTTRegistryService;
import Core.SchedulerService;
import Core.TimerService;
import Physics2d.Systems;
import kangaru;

export namespace Physics2d {

	void initPhysics2dSubSystems(Physics2dSystems&, kgr::container&);

	struct Physics2dSystemsService
		: kgr::single_service<
			  Physics2dSystems, kgr::dependency<Core::EnTTRegistryService, Core::SchedulerService, Core::TimerService>>,
		  kgr::autocall<kgr::invoke_method<initPhysics2dSubSystems>> {};

} // namespace Physics2d
