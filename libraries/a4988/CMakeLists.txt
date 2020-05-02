set(NAME a4988)

set(SOURCES
    driver.cpp
    inc/${NAME}/driver.hpp
)

add_library(${NAME} STATIC ${SOURCES})

target_link_libraries(${NAME}
    ${PROJECT_NAME}-hal
    board_hardware
    timer
)

target_include_directories(${NAME} INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}/inc)
target_include_directories(${NAME} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/inc/${NAME})