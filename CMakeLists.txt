cmake_minimum_required(VERSION 4.1.0)
project(RUN C)

file(GLOB_RECURSE SOURCES "${CMAKE_CURRENT_SOURCE_DIR}/Examples/src/*.c")
# file(GLOB_RECURSE includes ./Examples/inc/*.h)

add_executable(RUN ${SOURCES})

if(DEFINED RUN)
    target_compile_definitions(RUN PUBLIC RUN=${RUN})
else()
    # Optionally define a default if the variable isn't set
    target_compile_definitions(RUN PUBLIC RUN=1)
endif()

target_compile_options(RUN PUBLIC -Wall)
target_include_directories(RUN PUBLIC ./Examples/inc)
