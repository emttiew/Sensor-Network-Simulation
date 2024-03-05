cmake_minimum_required(VERSION 3.16)

project(ConanCMakeProject)

enable_testing()

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++20 -O3 -Wall -Werror -Wpedantic -Wextra")
set(BIN_DIR ${PROJECT_BINARY_DIR}/bin)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${BIN_DIR})

add_subdirectory(src)
add_subdirectory(test)
