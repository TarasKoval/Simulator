option(CodeCoverage "CodeCoverage" ON)
set(CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/tests/cmake/modules/)

include(DownloadProject.cmake)
download_project(PROJ googletest
        GIT_REPOSITORY https://github.com/google/googletest.git
        GIT_TAG master
        UPDATE_DISCONNECTED 1
        )

include_directories(${GTEST_INCLUDE_DIR})

# Prevent GoogleTest from overriding our compiler/linker options
# when building with Visual Studio
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

add_subdirectory(${googletest_SOURCE_DIR} ${googletest_BINARY_DIR})

# Trivial example using gtest and gmock
add_executable(simulator_test
        ${PROJECT_SOURCE_DIR}/tests/src/simulatorTest.cpp
        ${PROJECT_SOURCE_DIR}/src/functions.cpp
        include/mockSimulator.h
        )

target_link_libraries(simulator_test
        gtest gtest_main gmock)

if (CodeCoverage MATCHES ON)
    set(CMAKE_CXX_FLAGS "-O0 -g -fprofile-arcs -ftest-coverage ")
    include(CodeCoverage)
    setup_target_for_coverage(coverage simulator_test coverage)
endif ()
