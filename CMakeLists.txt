 
cmake_minimum_required(VERSION 3.31)

find_package(box2d CONFIG REQUIRED)

set(physics2d-lib-src
        src/physics2d/systems/Box2dPhysicsSystem.cpp
        src/physics2d/systems/Physics2dSystems.cpp
)

set(physics2d-lib-modules
        src/physics2d/CollisionEvent.cppm
        src/physics2d/CollisionShape.cppm
        src/physics2d/Rigidbody2d.cppm
        src/physics2d/services/Physics2dSystemsService.cppm
        src/physics2d/systems/Box2dPhysicsSystem.cppm
        src/physics2d/systems/Physics2dSystems.cppm
)

set(physics2d-lib-reflection-modules
)

add_library(physics2d-lib STATIC ${physics2d-lib-src} ${physics2d-lib-modules} ${physics2d-lib-reflection-modules})

target_sources(physics2d-lib PUBLIC FILE_SET modules TYPE CXX_MODULES FILES ${physics2d-lib-modules} ${physics2d-lib-reflection-modules})
target_compile_features(physics2d-lib PUBLIC cxx_std_23)
target_link_libraries(physics2d-lib PUBLIC core-lib box2d::box2d)
target_include_directories(physics2d-lib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/src)

#add_subdirectory(tests)
