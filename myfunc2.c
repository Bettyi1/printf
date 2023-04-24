#include "main.h"
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

/**
 * h_ptr - function prints a pointer
 * @types: arguments
 * @buffer: buffer
 * @flags: flags
 * @width: width
 * @precision: precision
 * @size: size
 * Return: pointer value
 */
int h_ptr(va_list types, char buffer[],
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

	if ((flags & FLAG_O) && !(flags & FLAG_S))
		space = '0';
	if (flags & FLAG_A)
		zeros = '+', len++;
	else if (flags & FLAG_P)
		zeros = ' ', len++;

	index++;

		return (p_wptr(buffer, index, len,
		width, flags, space, zeros, space_start));
}

/**
 * h_immprint - function prints non printable chars
 * @types: arguments
 * @size: size
 * @buffer: input value
 * @flags: input value
 * @precision: precision
 * @width: input value
 * Return: char
 */

int h_immprint(va_list types, char buffer[],
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
		if (U_printx(str[j]))
			buffer[j + update] = str[j];
		else
			update += u_hexadeci(str[j], buffer, j + update);

		j++;
	}

	buffer[j + update] = '\0';

	return (write(1, buffer, j + update));
}

/**
 * h_rev - function reverses string and print it out
 * @types: arguments
 * @buffer: buffer
 * @flags: flags
 * @width: width
 * @precision: precision
 * @size: size
 * Return: reversed string
 */

int h_rev(va_list types, char buffer[],
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
 * rot_string - function prints a string in rot13 format.
 * @types: arguments
 * @buffer: buffer
 * @flags:  flags
 * @width: width
 * @precision: precision
 * @size: size
 * Return: string in rot13style
 */
int rot_string(va_list types, char buffer[],
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
