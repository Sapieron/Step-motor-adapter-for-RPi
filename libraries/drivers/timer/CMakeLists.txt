set(NAME timer)

set(SOURCES
    ${NAME}.cpp
    inc/${NAME}/${NAME}.hpp
)

add_library(${NAME} STATIC ${SOURCES})

target_link_libraries(${NAME}
    ${PROJECT_NAME}-hal
    base
)

target_include_directories(${NAME} INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}/inc)
target_include_directories(${NAME} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/inc/${NAME})
