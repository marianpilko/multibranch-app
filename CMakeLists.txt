cmake_minimum_required(VERSION 3.14)
project(app)

# GoogleTest requires at least C++14
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# GTEST
include(FetchContent)
FetchContent_Declare(
    googletest
    # Specify the commit you depend on and update it regularly.
    URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

add_library(app STATIC
    # Source files
    src/app.cpp
    # Header files
    inc/app.h
)

# GTEST

enable_testing()

add_executable(app_test
    # Source files
    test/app_test.cpp
    # Header files
)

target_link_libraries(
    app_test
    GTest::gtest_main
    app
)

include(GoogleTest)
gtest_discover_tests(app_test)