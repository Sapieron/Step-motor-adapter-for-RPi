set(COMM_SECURITY_CODE "0xBBCCDDEE" CACHE STRING "32-bit COMM security code written in hex with leading 0x")

add_definitions(-DSTM32F103CB)

# if(${CMAKE_BUILD_TYPE} STREQUAL "Debug")
#     add_definitions(-DUSE_FULL_ASSERT)
# endif()

set (ARCH cortex-m3)
set (CHIP STM32F103CB)
set (DEVICE STM32F103CBTx)

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
set (CMAKE_C_FLAGS "-std=gnu11 ${CWARN} ${CTUNING} ${CMCU} ${CCOVERAGE}")
set (CMAKE_CXX_FLAGS "-std=gnu++1z -fno-exceptions -fno-rtti ${CXXWARN} ${CTUNING} ${CMCU} ${CCOVERAGE}")
set (CMAKE_CXX_STANDARD 17)

set(DEBUG_COMP_OPTIONS "-DDEBUG -Og -g")
set(RELEASE_COMP_OPTIONS "-DNDEBUG -O2 ${LTO_SWITCH}")

set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} ${LTO_SWITCH}")

set(CMAKE_C_FLAGS_DEBUG ${DEBUG_COMP_OPTIONS})
set(CMAKE_CXX_FLAGS_DEBUG ${DEBUG_COMP_OPTIONS})
set(CMAKE_C_FLAGS_RELEASE ${RELEASE_COMP_OPTIONS})
set(CMAKE_CXX_FLAGS_RELEASE ${RELEASE_COMP_OPTIONS})

set(LINKER_SCRIPT ${CMAKE_CURRENT_LIST_DIR}/stm32f103.ld)

set(BASE_ADDRESS_MCU 0x20000000)
# It used to be LOWER_ADDRESS and UPPER_ADDRES, as in EFM32 there are two different memory sections