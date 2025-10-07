 
cmake_minimum_required(VERSION 3.31)

find_package(box2d CONFIG REQUIRED)

set(ortha-physics2d-src
        src/physics2d/services/Physics2dSystemsService.cpp
        src/physics2d/systems/Box2dPhysicsSystem.cpp
        src/physics2d/systems/Physics2dSystems.cpp
)

set(ortha-physics2d-modules
        src/physics2d/ApplyForceRequest.cppm
        src/physics2d/BoxCollisionShape.cppm
        src/physics2d/CircleCollisionShape.cppm
        src/physics2d/CollisionEvent.cppm
        src/physics2d/CollisionShape.cppm
        src/physics2d/Rigidbody2d.cppm
        src/physics2d/services/Box2dPhysicsSystemService.cppm
        src/physics2d/services/Physics2dSystemsService.cppm
        src/physics2d/systems/Box2dPhysicsSystem.cppm
        src/physics2d/systems/Physics2dSystems.cppm
)

set(ortha-physics2d-reflection-src
        src/physics2d-reflection/Reflection.cpp
)

set(ortha-physics2d-reflection-modules
        src/physics2d-reflection/BoxCollisionShape.cppm
        src/physics2d-reflection/CircleCollisionShape.cppm
        src/physics2d-reflection/CollisionShape.cppm
        src/physics2d-reflection/Reflection.cppm
        src/physics2d-reflection/Ridigbody2d.cppm
)

add_library(ortha-physics2d STATIC ${ortha-physics2d-src} ${ortha-physics2d-modules} ${ortha-physics2d-reflection-src} ${ortha-physics2d-reflection-modules})

target_sources(ortha-physics2d PUBLIC FILE_SET modules TYPE CXX_MODULES FILES ${ortha-physics2d-modules} ${ortha-physics2d-reflection-modules})
target_compile_features(ortha-physics2d PUBLIC cxx_std_23)
target_link_libraries(ortha-physics2d PUBLIC ortha-core box2d::box2d)
target_include_directories(ortha-physics2d PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/src)

#add_subdirectory(tests)
