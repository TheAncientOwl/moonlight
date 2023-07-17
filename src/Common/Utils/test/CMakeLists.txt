file(GLOB SOURCE_FILES "*.cpp")
add_executable(MoonlightCommonUtilsTest ${SOURCE_FILES})

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/../src)

target_link_libraries(MoonlightCommonUtilsTest PRIVATE
    gtest
    gtest_main
    MoonlightCommonUtils
)

include(GoogleTest)
gtest_discover_tests(MoonlightCommonUtilsTest)
