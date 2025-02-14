#ifndef USB_UART_CONFIG_H
#define USB_UART_CONFIG_H

#include <stdint.h>

// Configuration structure for the USB-UART interface
typedef struct {
  const char* device_path;
  speed_t baud_rate;
} usb_uart_config_t;

// Function to set the device path
void usb_uart_config_set_device_path(usb_uart_config_t* config, const char* device_path);

// Function to set the baud rate
void usb_uart_config_set_baud_rate(usb_uart_config_t* config, speed_t baud_rate);

#endif  // USB_UART_CONFIG_H
