module;

#include <utility>

module Physics2d.Systems;

namespace Physics2d {

	Physics2dSystems::Physics2dSystems(entt::registry& registry, Core::Scheduler& scheduler, Core::Timer& timer)
		: mRegistry{ registry }
		, mScheduler{ scheduler } {

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
