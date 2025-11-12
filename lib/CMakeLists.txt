

file(GLOB_RECURSE SRC_FILES *.c)
target_sources(goose60_fw PUBLIC ${SRC_FILES})

add_library(gooselib
    ${SRC_FILES}
)

target_include_directories(gooselib PUBLIC
    ${CMAKE_CURRENT_LIST_DIR}
)

target_link_libraries(gooselib PUBLIC pico_stdlib pico_unique_id tinyusb_device tinyusb_board)