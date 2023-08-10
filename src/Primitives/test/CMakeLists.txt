file(GLOB SOURCE_FILES "*.cpp")
add_executable(MoonlightPrimitivesTests ${SOURCE_FILES})

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/../src)

target_link_libraries(MoonlightPrimitivesTests PRIVATE
    gtest
    gtest_main
    MoonlightPrimitives
)

include(GoogleTest)
gtest_discover_tests(MoonlightPrimitivesTests)
