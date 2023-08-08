file(GLOB SOURCE_FILES "*.cpp")
add_executable(MoonlightCommonPrimitivesTest ${SOURCE_FILES})

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/../src)

target_link_libraries(MoonlightCommonPrimitivesTest PRIVATE
    gtest
    gtest_main
    MoonlightCommonPrimitives
)

include(GoogleTest)
gtest_discover_tests(MoonlightCommonPrimitivesTest)
