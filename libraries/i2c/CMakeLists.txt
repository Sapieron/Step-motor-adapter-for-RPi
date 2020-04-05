set(NAME i2c)

set(SOURCES
	driver.cpp
)

add_library(${NAME} STATIC ${SOURCES})

target_link_libraries(${NAME}
	platform
	base
	gpio
)

target_include_directories(${NAME} INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}/inc)
target_include_directories(${NAME} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/inc/${NAME})
