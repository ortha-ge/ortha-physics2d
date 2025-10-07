export module Ortha.Physics2d.Box2dPhysicsSystemService;

export import Ortha.Physics2d.Box2dPhysicsSystem;

import Ortha.Core.EnTTRegistryService;
import Ortha.Core.SchedulerService;
import Ortha.Core.TimerService;
import kangaru;

export namespace Ortha::Physics2d {

	struct Box2dPhysicsSystemService
		: kgr::single_service<
			  Box2dPhysicsSystem,
			  kgr::dependency<Core::EnTTRegistryService, Core::SchedulerService, Core::TimerService>> {};

}