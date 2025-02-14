#ifndef USB_UART_INTERFACE_H
#define USB_UART_INTERFACE_H

#include <stdint.h>

#include "usb_uart_config.h"  // Include the configuration header

// Function to initialize the USB-UART interface
int usb_uart_init(const usb_uart_config_t* config);

// Function to send a UART packet
int send_uart_packet(unsigned char* data, int data_len);

void usb_uart_interface_function();

#endif  // USB_UART_INTERFACE_H
