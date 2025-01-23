cmake_minimum_required(VERSION 3.10)

project(tsu VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(TSU_MAJOR_VERSION ${PROJECT_VERSION_MAJOR})
set(TSU_MINOR_VERSION ${PROJECT_VERSION_MINOR})
set(TSU_PATCH_VERSION ${PROJECT_VERSION_PATCH})

file(GLOB_RECURSE SOURCES "src/*.cpp")

include_directories(
    include
)

add_executable(${PROJECT_NAME} ${SOURCES})
target_link_libraries(${PROJECT_NAME} PRIVATE -lssl -lcrypto)

install(TARGETS ${PROJECT_NAME}
        RUNTIME DESTINATION bin)
