set(NAME MotorController)

set(SOURCES
    MotorController.cpp
    inc/${NAME}/MotorController.hpp
)

add_library(${NAME} STATIC ${SOURCES})

target_link_libraries(${NAME}
    ${PROJECT_NAME}-hal
    a4988
)

target_include_directories(${NAME} INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}/inc)
target_include_directories(${NAME} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/inc/${NAME})