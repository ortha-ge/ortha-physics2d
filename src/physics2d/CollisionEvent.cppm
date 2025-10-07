export module Ortha.Physics2d.CollisionEvent;

import entt;

export namespace Ortha::Physics2d {

	struct CollisionEvent {
		const entt::entity primary { entt::null };
		const entt::entity secondary{ entt::null };
	};

} // namespace Ortha::Physics2d