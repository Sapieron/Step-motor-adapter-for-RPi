set(SOURCES
)

add_definitions(-DSTM32F103xB -DDEVBOARD)

add_library(platform INTERFACE ${SOURCES})

target_link_libraries(platform INTERFACE base)

target_include_directories(platform INTERFACE ${CMAKE_CURRENT_LIST_DIR}/inc)
