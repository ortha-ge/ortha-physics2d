
cmake_minimum_required(VERSION 3.31)

find_package(Catch2 3 REQUIRED)

set(ortha-physics2d-tests-src
        Box2dPhysicsSystemTests.cpp
)

set(ortha-physics2d-tests-modules
)

add_executable(ortha-physics2d-tests ${ortha-physics2d-tests-src})

target_sources(ortha-physics2d-tests PUBLIC FILE_SET modules TYPE CXX_MODULES FILES ${ortha-physics2d-tests-modules})
target_compile_features(ortha-physics2d-tests PUBLIC cxx_std_23)
target_link_libraries(ortha-physics2d-tests PRIVATE core-lib Catch2::Catch2WithMain)

#add_custom_target(ortha-physics2d-tests-assets
#        COMMAND ${CMAKE_COMMAND} -E copy_directory_if_different
#        "${CMAKE_CURRENT_SOURCE_DIR}/assets/"
#        "$<TARGET_FILE_DIR:ortha-physics2d-tests>/assets/"
#        COMMENT "Copying assets"
#)

#add_dependencies(ortha-physics2d-tests ortha-physics2d-tests-assets)

include(CTest)
include(Catch)
catch_discover_tests(ortha-physics2d-tests)
