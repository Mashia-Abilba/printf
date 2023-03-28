#include "main.h"

/**
 * is_printable - checks if a character is printable
 * @c: character to be checked
 * Return: 1 if c is printable and 0 if otherwise
 */
int is_printable(char c)
{
	if (c >= 32 && c < 127)
		return (1);

	return (0);
}

/**
 * append_hexa_code - append ascii to hexadecimal to buffer
 * @buffer: array of chararcters
 * @i: index at which to start appending
 * @ascii_code: ASCII CODE
 * Return: 3
 */
int append_hexa_code(char ascii_code, char buffer[], int i)
{
	char map_to[] = "0123456789ABCDEF";

	if (ascii_code < 0)
		ascii_code *= -1;

	buffer[i++] = '\\';
	buffer[i++] = 'x';

	buffer[i++] = map_to[ascii_code / 16];
	buffer[i] = map_to[ascii_code % 16];

	return (3);
}

/**
 * is_digit - verifies if a character is a digit
 * @c: character to be evaluated
 *
 * Return: 1 if character is a digit and 0 if otherwise
 */
int is_digit(char c)
{
	if (c >= '0' && c <= '9')
		return (1);

	return (0);
}

/**
 * convert_size_number - casts a number to the specifiedsize
 * @num: number to be casted
 * @sizert_size_number - casts a number to the specific ified size
 * @size: number indicating the type to be casted
 * Return: casted value
 */
long int convert_size_number(long int num, int size)
{
	if (size == S_LONG)
		return (num);
	else if (size == S_SHORT)
		return ((short)num);

	return ((int)num);
}

/**
 * convert_size_unsgned - casts a number to the specified size
 * @num: number to be casted
 * @size: number indicating the type to be casted
 * Return: casted value of num
 */

long int_convert_size_unsgned(unsigned long int num, int size)
{
	if (size == S_LONG)
		return (num);
	else if (size == S_SHORT)
		return ((unsigned short)num);

	return ((unsigned int)num);
}
