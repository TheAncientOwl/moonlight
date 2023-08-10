file(GLOB SOURCE_FILES "*.cpp")
add_executable(MoonlightQueryTests ${SOURCE_FILES})

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/../src)

target_link_libraries(MoonlightQueryTests PRIVATE
    gtest
    gtest_main
    MoonlightQuery
)

include(GoogleTest)
gtest_discover_tests(MoonlightQueryTests)
