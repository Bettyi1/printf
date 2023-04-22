#include "main.h"
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

/**
 * print_pointer - function prints a pointer
 * @types: arguments
 * @buffer: buffer
 * @flags: flags
 * @width: width
 * @precision: precision
 * @size: size
 * Return: pointer value
 */
int print_pointer(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	char zeros = 0, space = ' ';
	int index = BUFF_SIZE - 2, len = 2, space_start = 1;
	unsigned long mynum_addrs;
	char map_to[] = "0123456789abcdef";
	void *pa = va_arg(types, void *);

	UNUSED(width);
	UNUSED(size);

	if (pa == NULL)
		return (write(1, "(nil)", 5));

	buffer[BUFF_SIZE - 1] = '\0';
	UNUSED(precision);

	mynum_addrs = (unsigned long)pa;

	while (mynum_addrs > 0)
	{
		buffer[index--] = map_to[mynum_addrs % 16];
		mynum_addrs /= 16;
		len++;
	}

	if ((flags & F_ZERO) && !(flags & F_MINUS))
		space = '0';
	if (flags & F_PLUS)
		zeros = '+', len++;
	else if (flags & F_SPACE)
		zeros = ' ', len++;

	index++;

		return (write_pointer(buffer, index, len,
		width, flags, space, zeros, space_start));
}

/**
 * print_non_printable - function prints non printable chars
 * @types: arguments
 * @size: size
 * @buffer: input value
 * @flags:  input value
* @precision: precision
 * @width: input value
  * Return: char
 */

int print_non_printable(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	int j = 0;
int update = 0;
	char *str = va_arg(types, char *);

	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);

	if (str == NULL)
		return (write(1, "(null)", 6));

	while (str[j] != '\0')
	{
		if (is_printable(str[j]))
			buffer[j + update] = str[j];
		else
			update += append_hexa_code(str[j], buffer, j + update);

		j++;
	}

	buffer[j + update] = '\0';

	return (write(1, buffer, j + update));
}

/**
 * print_reverse - function reverses string and print it out
 * @types: arguments
 * @buffer: buffer
 * @flags: flags
 * @width: width
 * @precision: precision
 * @size: size
 * Return: reversed string
 */

int print_reverse(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	char *str;
	int k;
int count = 0;
char x;

	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(size);

	str = va_arg(types, char *);

	if (str == NULL)
	{
		UNUSED(precision);

		str = ")Null(";
	}
	for (k = 0; str[k]; k++)
		;

	for (k = k - 1; k >= 0; k--)
	{
		x = str[k];

		write(1, &x, 1);
		count++;
	}
	return (count);
}

/**
 * print_rot13string - function prints a string in rot13 format.
 * @types: arguments
 * @buffer: buffer
 * @flags:  flags
 * @width: width
 * @precision: precision
 * @size: size
 * Return: string in rot13style
 */
int print_rot13string(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	char y;
	char *str;
	unsigned int a = 0;
unsigned int b = 0;
	int count = 0;
	char input[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	char output[] = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";

	str = va_arg(types, char *);
	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);

	if (str == NULL)
		str = "(AHYY)";
	for (; str[a] ; a++)
	{
		for (; input[b] ; b++)
		{
			if (input[b] == str[a])
			{
				y = output[b];
				write(1, &y, 1);
				count++;
				break;
			}
		}
		if (!input[b])
		{
			y = str[a];
			write(1, &y, 1);
			count++;
		}
	}
	return (count);
}
