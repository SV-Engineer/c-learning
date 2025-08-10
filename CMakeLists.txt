cmake_minimum_required(VERSION 4.1.0)
project(RecursionWithSwitchStatements C)

# file(GLOB_RECURSE sources ./Examples/src/*.c)
# file(GLOB_RECURSE includes ./Examples/inc/*.h)

add_executable(RecursionWithSwitchStatements Examples/src/recursion_with_switch_statements.c)

target_compile_options(RecursionWithSwitchStatements PUBLIC -Wall)
target_include_directories(RecursionWithSwitchStatements PUBLIC ./Examples/inc)
