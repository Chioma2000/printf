#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <stdint.h>


void unsigned_number_to_string(uint64_t number, int base, char *buffer);
void number_to_string(int64_t number, int base, char *buffer);
void v_printf(const char *fmt, va_list args);
int _printf(const char *fmt, ...);
void confirm_reset(int *can_reset, int *state, int *is_long);
int length_of_formatted_string(const char *fmt);
void print_hex(va_list args, int *is_long, char *number_buffer);
void print_octal(va_list args, int *is_long, char *number_buffer);
void print_signed_int(va_list args, int *is_long, char *number_buffer);
void print_unsigned_int(va_list args, int *is_long, char *number_buffer);

#endif /* MAIN_H*/
