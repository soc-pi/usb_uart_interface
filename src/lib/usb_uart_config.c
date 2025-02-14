#include "usb_uart_config.h"

#include <string.h>

void usb_uart_config_set_device_path(usb_uart_config_t* config, const char* device_path) {
  if (config != NULL && device_path != NULL) {
    config->device_path = device_path;
  }
}

void usb_uart_config_set_baud_rate(usb_uart_config_t* config, speed_t baud_rate) {
  if (config != NULL) {
    config->baud_rate = baud_rate;
  }
}
