#ifndef __MAIN_H__
#define __MAIN_H__
#include <stdio.h>
#include <stdarg.h>

int _printf(const char *format, ...);
int _putchar(char c);

/**
 * struct - A new struct type defining conversion_specifier.
 * @specifier: A letter specifing the format/datatype of the data to be printed 
 * @print_fn: A function pointer to a function that prints
 *         a data type corresponding to the specifier.
 */
typedef struct
{
	char specifier;
	int (*print_fn)(va_list);
} conversion_specifier;

#endif
