file(GLOB SOURCE_FILES "*.cpp")
add_executable(MoonlightCommonTests ${SOURCE_FILES})

target_link_libraries(MoonlightCommonTests PRIVATE
    gtest
    gtest_main
    MoonlightCommonPrimitives
    MoonlightCommonQueryObject
)

include(GoogleTest)
gtest_discover_tests(MoonlightCommonTests)
