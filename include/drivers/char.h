/*
 * include/drivers/char.h
 */

#ifndef CHAR_H
#define CHAR_H

void serial_init(void);
void serial_putc(char c);
void serial_puts(const char *s);

#endif

/* End of file */
