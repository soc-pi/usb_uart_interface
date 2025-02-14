add_executable(${PROJECT_NAME}_test test_main.c)
target_link_libraries(${PROJECT_NAME}_test usb_uart_interface_lib)
add_test(NAME ${PROJECT_NAME}_test COMMAND ${PROJECT_NAME}_test)
