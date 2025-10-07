module Ortha.Physics2d.SystemsService;

import Ortha.RTTI.ReflectionContext;
import Ortha.RTTI.ReflectionContextStack;
import Ortha.Physics2d.Box2dPhysicsSystemService;
import Ortha.Physics2d.Reflection;

namespace Ortha::Physics2d {

	void initPhysics2dSubSystems(Physics2dSystems&, kgr::container& container) {
		using namespace Core;
		using namespace Ortha::RTTI;
		reflectAll(static_cast<ReflectionContext&>(getCurrentReflectionContext()));

		container.emplace<Box2dPhysicsSystemService>();
	}

} // namespace Ortha::Physics2d
