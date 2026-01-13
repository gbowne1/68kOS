/*
 * drivers/char/serial.c
 * Serial communication for debugging output
 */

#include <stdint.h>

#define UART_DATA_REG 0xFFF100
#define UART_STAT_REG 0xFFF102

void serial_putc(char c) {
    volatile uint8_t *status = (uint8_t *)UART_STAT_REG;
    volatile uint8_t *data   = (uint8_t *)UART_DATA_REG;

    /* Wait for Transmitter Empty */
    while (!(*status & 0x04));
    
    *data = (uint8_t)c;
}

void serial_puts(const char *s) {
    while (*s) {
        serial_putc(*s++);
    }
}

/* End of file */
