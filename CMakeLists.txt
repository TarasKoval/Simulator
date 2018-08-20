cmake_minimum_required(VERSION 3.5.1)
project(simulator)

set(CMAKE_CXX_STANDARD 11)

option(TESTS "Turn Tests On and Off" ON)

include_directories(${PROJECT_SOURCE_DIR}/include)

add_executable(${PROJECT_NAME} ${PROJECT_SOURCE_DIR}/src/main.cpp)

if (TESTS MATCHES ON)
    add_subdirectory(tests)
endif ()
