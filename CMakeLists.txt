cmake_minimum_required(VERSION 3.26)

# Set the policy for FetchContent timestamps (CMake 3.24+)
if(POLICY CMP0135)
    cmake_policy(SET CMP0135 NEW)
endif()

project(vectors_and_matrices_lib CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Enable CTest globally at the top level
enable_testing()

# 1. Header-Only Library Setup
add_library(vectors_and_matrices_lib INTERFACE
        include/VectorN.h
        include/Matrix.h)

target_include_directories(vectors_and_matrices_lib
        INTERFACE
        ${CMAKE_CURRENT_SOURCE_DIR}/include
)

target_compile_features(vectors_and_matrices_lib
        INTERFACE
        cxx_std_20
)

# 2. Fetch GoogleTest
include(FetchContent)
FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/refs/tags/v1.14.0.zip
        DOWNLOAD_EXTRACT_TIMESTAMP TRUE
)
# Force shared runtime on MSVC if building on Windows
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

# 3. Test Executable
add_executable(LinearAlgebraTests
        tests/test_vectors.cpp
        tests/test_matrices.cpp
)

target_link_libraries(LinearAlgebraTests
        PRIVATE
        vectors_and_matrices_lib
        gtest_main
)

# 4. Automatically Discover Tests for CTest / CLion
include(GoogleTest)
gtest_discover_tests(LinearAlgebraTests)