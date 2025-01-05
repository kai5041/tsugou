cmake_minimum_required(VERSION 3.10)

project(tsu VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

configure_file(
    "include/tsu/version.hpp.in",
    "include/tsu/version.hpp"
)

file(GLOB_RECURSE SOURCES "src/*.cpp")

include_directories(
    include
)

add_executable(${PROJECT_NAME} ${SOURCES})

install(TARGETS ${PROJECT_NAME}
        RUNTIME DESTINATION bin)
