module Physics2d.SystemsService;

import Ortha.RTTI.ReflectionContext;
import Ortha.RTTI.ReflectionContextStack;
import Physics2d.Box2dPhysicsSystemService;
import Physics2d.Reflection;

namespace Physics2d {

	void initPhysics2dSubSystems(Physics2dSystems&, kgr::container& container) {
		using namespace Core;
		using namespace Ortha::RTTI;
		reflectAll(static_cast<ReflectionContext&>(getCurrentReflectionContext()));

		container.emplace<Box2dPhysicsSystemService>();
	}

} // namespace Physics2d
