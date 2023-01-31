cmake_minimum_required(VERSION 3.22)
project("Gtest")

find_package(GTest REQUIRED)

add_executable(tests.out tests.cpp)
target_link_libraries(tests.out ${GTEST_LIBRARIES})

enable_testing()

add_test(SquareRootTest tests.out)