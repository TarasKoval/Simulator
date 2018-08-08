cmake_minimum_required(VERSION 3.5.1)
project(math)

set(CMAKE_CXX_STANDARD 11)

include_directories(${PROJECT_SOURCE_DIR}/include)

set(SOURCES
        ${PROJECT_SOURCE_DIR}/src/main.cpp
        ${PROJECT_SOURCE_DIR}/src/functions.cpp
        ${PROJECT_SOURCE_DIR}/include/simulator.h
        )

add_executable(${PROJECT_NAME} ${SOURCES})

add_subdirectory(tests)
