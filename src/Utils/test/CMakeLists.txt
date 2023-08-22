file(GLOB SOURCE_FILES "*.cpp")
add_executable(MoonlightUtilsTests ${SOURCE_FILES})

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/../src)

target_link_libraries(MoonlightUtilsTests PRIVATE
    gtest
    gtest_main
    MoonlightUtils
)

include(GoogleTest)
gtest_discover_tests(MoonlightUtilsTests)
