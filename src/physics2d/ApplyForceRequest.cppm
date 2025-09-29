export module Physics2d.ApplyForceRequest;

import glm;

export namespace Physics2d {

	enum class ForceType {
		Force,
		Impulse
	};

	struct ApplyForceRequest {
		ForceType type{ ForceType::Force };
		glm::vec2 force{};
		glm::vec2 center{};
	};

} // namespace Physics2d
