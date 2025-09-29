export module Physics2d.CollisionEvent;

import entt;

export namespace Physics2d {

	struct CollisionEvent {
		const entt::entity primary { entt::null };
		const entt::entity secondary{ entt::null };
	};

} // namespace Physics2d