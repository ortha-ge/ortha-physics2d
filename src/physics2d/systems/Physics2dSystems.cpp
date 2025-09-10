module;

#include <entt/entt.hpp>

module Physics2d.Systems;

namespace Physics2d {

	Physics2dSystems::Physics2dSystems(Core::EnTTRegistry& registry, Core::Scheduler& scheduler, Core::Timer& timer)
		: mRegistry{ registry }
		, mScheduler{ scheduler }
		, mBox2dPhysicsSystem(registry, scheduler, timer) {

		mTickHandle = mScheduler.schedule([this] {
			tickSystem(mRegistry);
		});
	}

	Physics2dSystems::~Physics2dSystems() {
		mScheduler.unschedule(std::move(mTickHandle));
	}

	void Physics2dSystems::tickSystem(entt::registry& registry) {

	}

} // namespace Physics2d
