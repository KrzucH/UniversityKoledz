cmake_minimum_required(VERSION 3.14)
project(Koledz)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)

set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

add_executable(${PROJECT_NAME} src/main.cpp src/database.cpp src/student.cpp src/person.cpp src/employee.cpp src/generator.cpp)

enable_testing()

add_executable(hello_test  src/tests.cpp src/database.cpp src/student.cpp src/person.cpp src/employee.cpp src/generator.cpp)
target_link_libraries(hello_test  GTest::gtest_main)

include(GoogleTest)
gtest_discover_tests(hello_test)
