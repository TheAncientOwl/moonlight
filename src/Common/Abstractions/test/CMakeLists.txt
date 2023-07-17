file(GLOB SOURCE_FILES "*.cpp")
add_executable(MoonlightCommonTypesTest ${SOURCE_FILES})

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/../src)

target_link_libraries(MoonlightCommonTypesTest PRIVATE
    gtest
    gtest_main
    MoonlightCommonTypes
)

include(GoogleTest)
gtest_discover_tests(MoonlightCommonTypesTest)
