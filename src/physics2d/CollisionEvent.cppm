module;

#include <entt/entity/entity.hpp>

export module Physics2d.CollisionEvent;

export namespace Physics2d {

	struct CollisionEvent {
		const entt::entity primary { entt::null };
		const entt::entity secondary{ entt::null };
	};

} // namespace Physics2d