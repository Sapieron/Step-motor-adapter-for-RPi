INCLUDE(CMakeForceCompiler)

set(CMAKE_SYSTEM_NAME Generic)

set(CMAKE_CXX_USE_RESPONSE_FILE_FOR_INCLUDES ON)
set(CMAKE_C_USE_RESPONSE_FILE_FOR_INCLUDES ON)
set(CMAKE_NEED_RESPONSE ON)

find_program(CC NAMES arm-none-eabi-gcc PATHS $ENV{ARM_TOOLCHAIN})
find_program(CXX NAMES arm-none-eabi-g++ PATHS $ENV{ARM_TOOLCHAIN})

find_program(CMAKE_GCOV NAMES arm-none-eabi-gcov PATHS $ENV{ARM_TOOLCHAIN})
find_program(CMAKE_AR NAMES arm-none-eabi-gcc-ar PATHS $ENV{ARM_TOOLCHAIN})
find_program(CMAKE_RANLIB NAMES arm-none-eabi-gcc-ranlib PATHS $ENV{ARM_TOOLCHAIN})
find_program(CMAKE_OBJCOPY NAMES arm-none-eabi-objcopy PATHS $ENV{ARM_TOOLCHAIN})
find_program(CMAKE_OBJDUMP NAMES arm-none-eabi-objdump PATHS $ENV{ARM_TOOLCHAIN})
find_program(CMAKE_GCC_SIZE NAMES arm-none-eabi-size PATHS $ENV{ARM_TOOLCHAIN})
find_program(GDB NAMES arm-none-eabi-gdb-py PATHS $ENV{ARM_TOOLCHAIN})

set(CMAKE_C_COMPILER ${CC})
set(CMAKE_CXX_COMPILER ${CXX})

# As CMake tries to compile executable using ,,standard" arguments it fails on
# checking arm-gcc compiler. Instead try to compile a static library, which avoids
# running linker and such an approach is intended for cross-compiling
set(CMAKE_TRY_COMPILE_TARGET_TYPE "STATIC_LIBRARY")

find_program(JLINK NAMES JLink JLinkExe PATHS $ENV{ARM_TOOLCHAIN} $ENV{JLINK_PATH})
find_program(JLinkGDBServer NAMES JLinkGDBServerCL PATHS $ENV{ARM_TOOLCHAIN} $ENV{JLINK_PATH})

# FIND_PACKAGE(Doxygen) # TODO add doxygen in future 

set(CMAKE_EXECUTABLE_FORMAT ELF)

if(${CMAKE_GENERATOR} STREQUAL "MinGW Makefiles")
    find_program(CMAKE_MAKE_PROGRAM NAMES make PATHS $ENV{ARM_TOOLCHAIN})
endif()