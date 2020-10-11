set(NAME base)

set(SOURCES
    crc.cpp
)

add_library(${NAME} STATIC ${SOURCES})


target_include_directories(${NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/inc)
target_include_directories(${NAME} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/inc/base)
