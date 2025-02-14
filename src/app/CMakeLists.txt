add_executable(${PROJECT_NAME} main.c)
target_link_libraries(${PROJECT_NAME} usb_uart_interface_lib)
