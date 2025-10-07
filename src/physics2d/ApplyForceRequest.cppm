export module Ortha.Physics2d.ApplyForceRequest;

import glm;

export namespace Ortha::Physics2d {

	enum class ForceType {
		Force,
		Impulse
	};

	struct ApplyForceRequest {
		ForceType type{ ForceType::Force };
		glm::vec2 force{};
		glm::vec2 center{};
	};

} // namespace Ortha::Physics2d
