
export module Ortha.Physics2d.SystemsService;

import Ortha.Core.EnTTRegistryService;
import Ortha.Core.SchedulerService;
import Ortha.Core.TimerService;
import Ortha.Physics2d.Systems;
import kangaru;

export namespace Ortha::Physics2d {

	void initPhysics2dSubSystems(Physics2dSystems&, kgr::container&);

	struct Physics2dSystemsService
		: kgr::single_service<
			  Physics2dSystems, kgr::dependency<Core::EnTTRegistryService, Core::SchedulerService, Core::TimerService>>,
		  kgr::autocall<kgr::invoke_method<initPhysics2dSubSystems>> {};

} // namespace Ortha::Physics2d
