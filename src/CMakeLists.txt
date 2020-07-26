set(NAME step_motor_adapter)

set(SOURCES
    ${STARTUP_FILE}
    main.cpp
    mcu/board.cpp
    board_access.cpp
)

add_executable(${NAME} ${SOURCES})

set_target_properties(${NAME} PROPERTIES LINK_FLAGS "-mcpu=cortex-m3 -mthumb -mfloat-abi=soft -T ${LINKER_SCRIPT} -L ${MCU_PLATFORM_PATH} -Wl,--gc-sections -lm -specs=nano.specs -specs=nosys.specs")

target_include_directories(${NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/mcu/inc)

target_link_libraries(${NAME}
    board_hardware
    base
    platform
    gpio
    uart
    terminal
    a4988
    motorController
)

target_generate_hex(${NAME})
target_generate_bin(${NAME})

target_memory_report(${NAME})

target_asm_listing(${NAME})

target_jlink_flash(${NAME} ${BASE_ADDRESS_MCU})
