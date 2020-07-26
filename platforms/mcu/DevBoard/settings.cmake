set(COMM_SECURITY_CODE "0xBBCCDDEE" CACHE STRING "32-bit COMM security code written in hex with leading 0x")

add_definitions(-DSTM32F103RB -DSTM32F103xB)

set (ARCH cortex-m3)
set (CHIP STM32F103XB)
set (DEVICE STM32F103RBTx)

if(${ENABLE_COVERAGE})
    set (CCOVERAGE "-fprofile-arcs -ftest-coverage")
else()
    set (CCOVERAGE )
endif()

if(ENABLE_LTO)
    set(LTO_SWITCH "-flto")
endif()

set (CWARN "-Wall -Wstrict-prototypes -Wextra -Werror -Wno-unused-parameter")
set (CXXWARN "-Wall -Wextra -Werror")
set (CTUNING "-ggdb -pedantic -fomit-frame-pointer -ffunction-sections -fdata-sections")
set (CMCU "-mtune=cortex-m3 -MMD -MP -mcpu=cortex-m3 -mthumb -march=armv7-m -mlittle-endian -mfix-cortex-m3-ldrd -mno-thumb-interwork")
set (CMAKE_C_FLAGS "-std=c18 ${CWARN} ${CTUNING} ${CMCU} ${CCOVERAGE}")
set (CMAKE_CXX_FLAGS "-std=c++2a -fno-exceptions -fno-rtti ${CXXWARN} ${CTUNING} ${CMCU} ${CCOVERAGE}")
set (CMAKE_CXX_STANDARD 20)

set(DEBUG_COMP_OPTIONS "-DDEBUG -Og -O0 -g")
set(RELEASE_COMP_OPTIONS "-DNDEBUG -O2 ${LTO_SWITCH}")

set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} ${LTO_SWITCH}")

set(CMAKE_C_FLAGS_DEBUG ${DEBUG_COMP_OPTIONS})
set(CMAKE_CXX_FLAGS_DEBUG ${DEBUG_COMP_OPTIONS})
set(CMAKE_C_FLAGS_RELEASE ${RELEASE_COMP_OPTIONS})
set(CMAKE_CXX_FLAGS_RELEASE ${RELEASE_COMP_OPTIONS})

set(LINKER_SCRIPT ${CMAKE_SOURCE_DIR}/libraries/external/STM32CubeF1/Drivers/CMSIS/Device/ST/STM32F1xx/Source/Templates/gcc/linker/STM32F103XB_FLASH.ld)
set(STARTUP_FILE  ${CMAKE_SOURCE_DIR}/libraries/external/STM32CubeF1/Drivers/CMSIS/Device/ST/STM32F1xx/Source/Templates/gcc/startup_stm32f103xb.s)
set(BASE_ADDRESS_MCU 0x20000000)