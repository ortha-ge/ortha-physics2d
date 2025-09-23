export module Physics2d.Box2dPhysicsSystemService;

export import Physics2d.Box2dPhysicsSystem;

import Core.EnTTRegistryService;
import Core.SchedulerService;
import Core.TimerService;
import kangaru;

export namespace Physics2d {

	struct Box2dPhysicsSystemService
		: kgr::single_service<
			  Box2dPhysicsSystem,
			  kgr::dependency<Core::EnTTRegistryService, Core::SchedulerService, Core::TimerService>> {};

}