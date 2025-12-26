

cmake_minimum_required(VERSION 3.13)

set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -O3")

# Initialise pico_sdk from installed location
# (note this can come from environment, CMake cache etc)

# == DO NOT EDIT THE FOLLOWING LINES for the Raspberry Pi Pico VS Code Extension to work ==
if(WIN32)
    set(USERHOME $ENV{USERPROFILE})
else()
    set(USERHOME $ENV{HOME})
endif()
set(sdkVersion 2.2.0)
set(toolchainVersion 14_2_Rel1)
set(picotoolVersion 2.2.0-a4)
set(picoVscode ${USERHOME}/.pico-sdk/cmake/pico-vscode.cmake)
if (EXISTS ${picoVscode})
    include(${picoVscode})
endif()


set(PICO_BOARD pico CACHE STRING "Board type")

add_executable(goose60_fw)

# Pull in Raspberry Pi Pico SDK (must be before project)
include(pico_sdk_import.cmake)

project(goose60_fw C CXX ASM)

# Initialise the Raspberry Pi Pico SDK
pico_sdk_init()

pico_enable_stdio_uart(goose60_fw 1)
pico_enable_stdio_usb(goose60_fw 1)

# Add source files in src/ directory
# file(GLOB_RECURSE SRC_FILES lib/*.c)
# target_sources(goose60_fw PUBLIC ${SRC_FILES})

add_subdirectory(lib)


target_sources(goose60_fw PUBLIC
        ${CMAKE_CURRENT_LIST_DIR}/main.c
        # ${CMAKE_CURRENT_LIST_DIR}/usb_descriptors.c
        )

# Make sure TinyUSB can find tusb_config.h
# target_include_directories(goose60_fw PUBLIC
#         ${CMAKE_CURRENT_LIST_DIR})

# In addition to pico_stdlib required for common PicoSDK functionality, add dependency on tinyusb_device
# for TinyUSB device support and tinyusb_board for the additional board support library used by the example
target_link_libraries(goose60_fw PUBLIC pico_stdlib pico_unique_id tinyusb_device tinyusb_board gooselib)

# Uncomment this line to enable fix for Errata RP2040-E5 (the fix requires use of GPIO 15)
#target_compile_definitions(goose60_fw PUBLIC PICO_RP2040_USB_DEVICE_ENUMERATION_FIX=1)

pico_add_extra_outputs(goose60_fw)

# add url via pico_set_program_url
# example_auto_set_url(goose60_fw)