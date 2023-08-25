cmake_minimum_required(VERSION 3.13)

add_library(usb_midi_device_ac_optional INTERFACE)
target_sources(usb_midi_device_ac_optional INTERFACE
    ${CMAKE_CURRENT_LIST_DIR}/usb_midi_dev_ac_optional.c
)
target_include_directories(usb_midi_device_ac_optional INTERFACE
 ${CMAKE_CURRENT_LIST_DIR}
)
target_link_libraries(usb_midi_device_ac_optional INTERFACE pico_stdlib tinyusb_device)

add_library(usb_midi_device_app_driver INTERFACE)
target_sources(usb_midi_device_app_driver INTERFACE
    ${CMAKE_CURRENT_LIST_DIR}/usb_midi_dev_app_driver.c
)
target_include_directories(usb_midi_device_app_driver INTERFACE
 ${CMAKE_CURRENT_LIST_DIR}
)
target_link_libraries(usb_midi_device_app_driver INTERFACE usb_midi_device_ac_optional)