cmake_minimum_required(VERSION 3.15)

project(mes C)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(SRC
    src/main.c
    src/io.c
    src/mesh.c
    src/integrals.c
    src/constants.c
)

add_executable(mes ${SRC})

target_include_directories(mes PRIVATE
    ${CMAKE_SOURCE_DIR}/src
)

set_target_properties(mes PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin
)

target_compile_options(mes PRIVATE
    $<$<CONFIG:Debug>:-Wall -g3 -ggdb -DDEBUG>
    $<$<CONFIG:Release>:-O3 -DN_DEBUG>
)

set_target_properties(mes PROPERTIES
    OUTPUT_NAME_DEBUG   mes
    OUTPUT_NAME_RELEASE mes
)
