module Physics2d.SystemsService;

import Core.ReflectionContext;
import Physics2d.Box2dPhysicsSystemService;
import Physics2d.Reflection;

namespace Physics2d {

	void initPhysics2dSubSystems(Physics2dSystems&, kgr::container& container) {
		using namespace Core;
		reflectAll(getCurrentReflectionContext());

		container.emplace<Box2dPhysicsSystemService>();
	}

} // namespace Physics2d
