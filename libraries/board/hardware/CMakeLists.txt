set(NAME board_hardware)

set(SOURCES
	hardware.cpp
	inc/hardware/gpio.hpp
    inc/hardware/hardware.hpp
    inc/hardware/gpio_internal.hpp
)

add_library(${NAME} STATIC ${SOURCES})

target_link_libraries(${NAME}
	platform
	base
	gpio
    uart
    a4988
    terminal
    motorController
    FS-IR02
)

target_include_directories(${NAME} INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}/inc)
target_include_directories(${NAME} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/inc/hardware)
