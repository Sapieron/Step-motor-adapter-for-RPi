cmake_minimum_required(VERSION 3.13 FATAL_ERROR)
set(OUTPUT_FILE_NAME "firmware")

if(NOT CMAKE_BUILD_TYPE)
    message(STATUS "CMAKE_BUILD_TYPE not set, defaulting to DEBUG")
    set(CMAKE_BUILD_TYPE DEBUG)
else()
    message(STATUS "CMAKE_BUILD_TYPE: ${CMAKE_BUILD_TYPE}")
endif()

message(STATUS "CMAKE_TOOLCHAIN_FILE: ${CMAKE_TOOLCHAIN_FILE}")

project(${OUTPUT_FILE_NAME} C CXX ASM)

include(cmake/utils.cmake)

add_subdirectory(drivers)

file(GLOB_RECURSE SOURCES CONFIGURE_DEPENDS
    ${CMAKE_CURRENT_SOURCE_DIR}/src/*.h
    ${CMAKE_CURRENT_SOURCE_DIR}/src/*.hxx
    ${CMAKE_CURRENT_SOURCE_DIR}/src/*.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/*.c
    ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cxx
    ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/*.s

    ${CMAKE_CURRENT_SOURCE_DIR}/libraries/gpio/*.h
    ${CMAKE_CURRENT_SOURCE_DIR}/libraries/gpio/*.hxx
    ${CMAKE_CURRENT_SOURCE_DIR}/libraries/gpio/*.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/libraries/gpio/*.c
    ${CMAKE_CURRENT_SOURCE_DIR}/libraries/gpio/*.cxx
    ${CMAKE_CURRENT_SOURCE_DIR}/libraries/gpio/*.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/libraries/gpio/*.s
)

add_executable(${PROJECT_NAME})

target_include_directories(${PROJECT_NAME}
    PRIVATE
        "${CMAKE_CURRENT_SOURCE_DIR}/src"
        "${CMAKE_CURRENT_SOURCE_DIR}/src/mcu/include"
        "${CMAKE_CURRENT_SOURCE_DIR}/src/payload/include"
        "${CMAKE_CURRENT_SOURCE_DIR}/libraries/gpio/inc"
        "${CMAKE_CURRENT_SOURCE_DIR}/libraries/i2c/inc"
        "${CMAKE_CURRENT_SOURCE_DIR}/libraries/uart/inc"
        "${CMAKE_CURRENT_SOURCE_DIR}/libraries"
)

target_sources(${PROJECT_NAME}
    PRIVATE
        ${SOURCES}
)

set_target_properties(${PROJECT_NAME}
    PROPERTIES
        SUFFIX ".elf"
        C_STANDARD 11
        C_EXTENSIONS ON
        CMAKE_C_STANDARD_REQUIRED ON
        CXX_STANDARD 20
        CXX_EXTENSIONS ON
        CMAKE_CXX_STANDARD_REQUIRED ON
)

target_compile_options(${PROJECT_NAME}
    PRIVATE
        -x c++
        -Wall
        -Wextra
        -Wpedantic
        -Wduplicated-cond
        -Wduplicated-branches
        -Wlogical-op
        -Wnull-dereference
        -Wshadow
        -Wconversion
        -Wsign-conversion
        -O0
)

target_link_libraries(${PROJECT_NAME}
    PRIVATE
        ${PROJECT_NAME}-hal
)

target_link_options(${PROJECT_NAME}
    PRIVATE
        -Wl,-Map=${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}.map,--cref
)

utils_target_set_linker_script(${PROJECT_NAME}
    ${CMAKE_CURRENT_SOURCE_DIR}/drivers/drivers/external/CMSIS/Device/ST/STM32F1xx/Source/Templates/gcc/linker/STM32F103XB_FLASH.ld
)

utils_target_generate_hex(${PROJECT_NAME})
utils_target_generate_bin(${PROJECT_NAME})
utils_target_print_size(${PROJECT_NAME})
