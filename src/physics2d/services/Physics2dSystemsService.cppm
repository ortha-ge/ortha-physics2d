
export module Physics2d.SystemsService;

import Core.EnTTRegistryService;
import Core.SchedulerService;
import Physics2d.Systems;
import kangaru;

export namespace Physics2d {

	class Physics2dSystemsService
		: public kgr::single_service<Physics2dSystems,
			  kgr::dependency<Core::EnTTRegistryService, Core::SchedulerService>> {};

} // namespace Physics2d
