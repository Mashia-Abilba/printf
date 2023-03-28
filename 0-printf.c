#include <stdio.h>
#include <stdarg.h>
#include <main.h>

int print_char(va_list args);
int print_str(va_list args);

/**
 * print_char - Prints a character.
 * @args: A va_list holding the character to be printed.
 *
 * Return: 1 always.
 */
int print_char(va_list args)
{
	char c;

	c = va_arg(args, int);
	putchar(c);
	return (1);
}

/**
 * print_str - Prints a string.
 * @args: A v_list holding the string to be printed.
 *
 * Return: The number of char in the string.
 */

int print_str(va_list args)
{
	char *s;
	int count = 0;

	s = va_arg(args, char *);

	while (*s)
	{
		putchar(*s);
		s++;
		count++;
	}
	return (count);
}

/**
 * _printf - Produces output according to a format.
 * @format: The format in which output is to be produced.
 *
 * Return: 0 on success, somethingelse otherwise.
 */
int _printf(const char *format, ...)
{
	conversion_specifier conv_table[] = {
		{'c', &print_char},
		{'s', &print_str},
		{'%', NULL}
	};
	conversion_specifier *specifier = NULL;
	int count = 0, i;
	va_list args;

	va_start(args, format);

	while (*format)
	{
		if (*format == '%')
		{
			format++;
			for (i = 0; i < sizeof(conv_table) / sizeof(conv_table[0]); i++)
			{
				if (*format == conv_table[i].specifier)
				{
					specifier = &conv_table[i];
					break;
				}
			}
			if (specifier == NULL)
			{
				count += print_char('%');
				count += print_char(*format);
			}
			else
				count += specifier->print_fn(args);
		}
		else
			count += print_char(*format);
		format++;
	}
	va_end(args);
	return (count);
