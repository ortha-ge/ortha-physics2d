
cmake_minimum_required(VERSION 3.31)

find_package(Catch2 3 REQUIRED)

set(physics2d-lib-tests-src
        Box2dPhysicsSystemTests.cpp
)

set(physics2d-lib-tests-modules
)

add_executable(physics2d-lib-tests ${physics2d-lib-tests-src})

target_sources(physics2d-lib-tests PUBLIC FILE_SET modules TYPE CXX_MODULES FILES ${physics2d-lib-tests-modules})
target_compile_features(physics2d-lib-tests PUBLIC cxx_std_23)
target_link_libraries(physics2d-lib-tests PRIVATE core-lib Catch2::Catch2WithMain)

#add_custom_target(physics2d-lib-tests-assets
#        COMMAND ${CMAKE_COMMAND} -E copy_directory_if_different
#        "${CMAKE_CURRENT_SOURCE_DIR}/assets/"
#        "$<TARGET_FILE_DIR:physics2d-lib-tests>/assets/"
#        COMMENT "Copying assets"
#)

#add_dependencies(physics2d-lib-tests physics2d-lib-tests-assets)

include(CTest)
include(Catch)
catch_discover_tests(physics2d-lib-tests)
