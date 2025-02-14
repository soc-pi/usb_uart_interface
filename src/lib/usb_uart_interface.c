#include "usb_uart_interface.h"

#include <stdio.h>  // For printf (optional, for debugging)

#include "usb_uart_config.h"

// Include necessary headers for USB and UART communication
#include <errno.h>  // for errno
#include <fcntl.h>
#include <termios.h>
#include <unistd.h>

// Replace these with the actual device path and baud rate
#define UART_DEVICE "/dev/ttyACM0"  // Example: Replace with your USB-UART device path
#define BAUD_RATE 115200            // Example: Replace with your desired baud rate

static int uart_fd = -1;  // File descriptor for the UART device

int usb_uart_init(const usb_uart_config_t* config) {
  // Implementation to initialize the USB-UART interface
  // This might involve opening the device, setting the baud rate, etc.

  // Check for null configuration
  if (config == NULL) {
    fprintf(stderr, "Error: Configuration cannot be NULL.\n");
    return -1;
  }

  // Example implementation (replace with your actual initialization code):
  uart_fd = open(config->device_path, O_RDWR | O_NOCTTY);
  if (uart_fd == -1) {
    perror("Error opening UART device");
    return -1;
  }

  struct termios tty;
  if (tcgetattr(uart_fd, &tty) != 0) {
    perror("Error getting UART attributes");
    close(uart_fd);
    return -1;
  }

  cfsetospeed(&tty, config->baud_rate);
  cfsetispeed(&tty, config->baud_rate);

  tty.c_cflag |= (CLOCAL | CREAD);  // Enable receiver and set local mode
  tty.c_cflag &= ~CRTSCTS;          // Disable hardware flow control
  tty.c_cflag &= ~CSIZE;
  tty.c_cflag |= CS8;                      // 8-bit characters
  tty.c_cflag &= ~PARENB;                  // No parity bit
  tty.c_cflag &= ~CSTOPB;                  // 1 stop bit
  tty.c_iflag &= ~IGNBRK;                  // Disable break processing
  tty.c_iflag &= ~(IXON | IXOFF | IXANY);  // Disable software flow control
  tty.c_lflag = 0;                         // No local flags
  tty.c_oflag = 0;                         // No output flags

  if (tcsetattr(uart_fd, TCSANOW, &tty) != 0) {
    perror("Error setting UART attributes");
    close(uart_fd);
    return -1;
  }

  printf("USB-UART interface initialized successfully.\n");
  return 0;
}

int send_uart_packet(unsigned char* data, int data_len) {
  // Implementation to send a UART packet
  // This might involve writing the data to the UART device

  if (uart_fd == -1) {
    printf("UART device not initialized.\n");
    return -1;
  }

  ssize_t bytes_written = write(uart_fd, data, data_len);
  if (bytes_written == -1) {
    perror("Error writing to UART device");
    return -1;
  }

  if (bytes_written != data_len) {
    printf("Warning: Only %ld bytes written out of %d.\n", bytes_written, data_len);
  }

  return 0;
}

void usb_uart_interface_function() {
  printf("This is a function from the usb_uart_interface library.\n");
}
