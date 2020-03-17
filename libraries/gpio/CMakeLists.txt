set(NAME gpio)

set(SOURCES
    driver.cpp
    inc/gpio/forward.hpp
    inc/gpio/driver.hpp
)

add_library(${NAME} STATIC ${SOURCES})

target_link_libraries(${NAME}
    ${PROJECT_NAME}-hal
)

target_include_directories(${NAME} INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}/inc)
target_include_directories(${NAME} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/inc)
