#ifndef __MAIN_H__
#define __MAIN_H__
#include <stdio.h>
#include <stdarg.h>

int _printf(const char *format, ...);
int _putchar(char c);
int _printf(const char *format, ...);
int print_c(va_list args);
int print_s(va_list args);
int print_percent(va_list args);
int (*get_func(char x))(va_list args);

/**
 * struct - A new struct type defining conversion_specifier.
 * @specifier: A letter specifing the format/datatype of the data to be printed 
 * @print_fn: A function pointer to a function that prints
 *         a data type corresponding to the specifier.
 */
typedef struct specifier
{
	char *valid;
	int (*f)(va_list);
} spec;
#endif
