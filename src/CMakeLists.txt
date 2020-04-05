set(NAME step_motor_adapter)

set(SOURCES
    main.cpp
    mcu/board.cpp
    mcu/inc/mcu/board.hpp
)

add_executable(${NAME} ${SOURCES})

set_target_properties(${NAME} PROPERTIES LINK_FLAGS "-T ${LINKER_SCRIPT} -L ${MCU_PLATFORM_PATH} -specs=nano.specs -specs=nosys.specs")

target_include_directories(${NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/mcu/inc )

target_link_libraries(${NAME}
    board_hardware
    base
    platform
    gpio
    uart
    i2c
    terminal
)

target_generate_hex(${NAME})
target_generate_bin(${NAME})

target_memory_report(${NAME})

target_asm_listing(${NAME})

target_jlink_flash(${NAME} ${BASE_ADDRESS_MCU})
