file(GLOB_RECURSE HAL_HEADERS CONFIGURE_DEPENDS
    ${CMAKE_CURRENT_SOURCE_DIR}/STM32CubeF1/Drivers/STM32F1xx_HAL_Driver/Inc/*.h
    ${CMAKE_CURRENT_SOURCE_DIR}/STM32CubeF1/Drivers/STM32F1xx_HAL_Driver/Inc/*.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/STM32CubeF1/Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS_V2/*.h
)

file(GLOB_RECURSE HAL_SOURCES CONFIGURE_DEPENDS
    ${CMAKE_CURRENT_SOURCE_DIR}/STM32CubeF1/Drivers/STM32F1xx_HAL_Driver/Src/*.c
    ${CMAKE_CURRENT_SOURCE_DIR}/STM32CubeF1/Drivers/STM32F1xx_HAL_Driver/Src/*.s
    ${CMAKE_CURRENT_SOURCE_DIR}/STM32CubeF1/Drivers/STM32F1xx_HAL_Driver/Src/*.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/STM32CubeF1/Drivers/CMSIS/Device/ST/STM32F1xx/Source/Templates/*.c
    ${CMAKE_CURRENT_SOURCE_DIR}/STM32CubeF1/Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS_V2/*.c
    ${CMAKE_CURRENT_SOURCE_DIR}/STM32CubeF1/Middlewares/Third_Party/FreeRTOS/Source/event_groups.c
    ${CMAKE_CURRENT_SOURCE_DIR}/STM32CubeF1/Middlewares/Third_Party/FreeRTOS/Source/queue.c
    ${CMAKE_CURRENT_SOURCE_DIR}/STM32CubeF1/Middlewares/Third_Party/FreeRTOS/Source/list.c
    ${CMAKE_CURRENT_SOURCE_DIR}/STM32CubeF1/Middlewares/Third_Party/FreeRTOS/Source/tasks.c
    ${CMAKE_CURRENT_SOURCE_DIR}/STM32CubeF1/Middlewares/Third_Party/FreeRTOS/Source/timers.c
    ${CMAKE_CURRENT_SOURCE_DIR}/STM32CubeF1/Middlewares/Third_Party/FreeRTOS/Source/portable/MemMang/heap_3.c
    ${CMAKE_CURRENT_SOURCE_DIR}/STM32CubeF1/Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM3/*.c
)

add_library(${PROJECT_NAME}-hal OBJECT)

target_include_directories(${PROJECT_NAME}-hal
    SYSTEM PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/STM32CubeF1/Drivers/STM32F1xx_HAL_Driver/Inc
        ${CMAKE_SOURCE_DIR}/src
        ${CMAKE_CURRENT_SOURCE_DIR}/STM32CubeF1/Drivers/CMSIS/Device/ST/STM32F1xx/Include
        ${CMAKE_CURRENT_SOURCE_DIR}/STM32CubeF1/Drivers/CMSIS/Include
        ${MCU_PLATFORM_PATH}/
        ${CMAKE_CURRENT_SOURCE_DIR}/STM32CubeF1/Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS_V2
        ${CMAKE_CURRENT_SOURCE_DIR}/STM32CubeF1/Middlewares/Third_Party/FreeRTOS/Source/include
        ${CMAKE_CURRENT_SOURCE_DIR}/STM32CubeF1/Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM3
)
# FIXME freertos shouldn't be name -hal module!
target_compile_definitions(${PROJECT_NAME}-hal
    PUBLIC
        STM32F103xx
)

target_sources(${PROJECT_NAME}-hal
    PUBLIC
        ${HAL_HEADERS}
    PRIVATE
        ${HAL_SOURCES}
)
