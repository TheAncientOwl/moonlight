cmake_minimum_required(VERSION 3.14)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project(Moonlight VERSION 0.1.0 LANGUAGES C CXX)

# Setup testing
include(CTest)
enable_testing()

# Setup library
include_directories(src)
add_subdirectory(src)

file(WRITE src/null.cpp "")
add_library(Moonlight src/null.cpp)

target_include_directories(Moonlight PRIVATE src)

# Setup CPack
set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
