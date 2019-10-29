#include <stdarg.h>
#include "holberton.h"

/**
 * p_mhex_r - prints number in base 16 recursively
 * @value: The number to be printed
 * @length: The amount of digits to be printed.
 * Return: integer length.
 */
int p_mhex_r(unsigned long value, int length)
{
	if (value / 16)
		length = p_mhex_r(value / 16, length + 1);
	if (value % 16 < 10)
		_putchar(value % 16 + 48);
	else
		_putchar(value % 16 + 87);
	return (length);
}


/**
 * p_mhex - From decimal to Hexadecimal in smallcaps
 * @args: The name for va_list
 *
 * Return: number length.
 * On error, -1 is returned.
 */
int p_mhex(va_list *args)
{
	int length = 2;
	unsigned long value = va_arg(*args, unsigned long);

	if (value == 0)
	{
		_putchar('(');
		_putchar('n');
		_putchar('i');
		_putchar('l');
		_putchar(')');
		length += 5;
	}
	else
	{
	_putchar('0');
	_putchar('x');
	length += p_mhex_r(value, length) + 1;
	}
	return (length);
}
