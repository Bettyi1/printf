#include "main.h"
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

/**
 * h_print - prints argument as specified
 * @fmt: string with format specifier
 * @list: arguments.
 * @ind: index iterator.
 * @buffer: buffer
 * @flags: flags
 * @width: width.
 * @precision: precision
 * @size: size
 * Return: 1, -1.
 */
int h_print(const char *fmt, int *ind, va_list list, char buffer[],
	int flags, int width, int precision, int size)
{
	int k = 0;
int len = 0;
int printed_char = -1;

	fmt_t fmt_types[] = {
		{'c', print_character23}, {'s', h_stringp}, {'%', _percenthandler},
		{'i', h_intr}, {'d', h_intr}, {'b', h_binary},
		{'u', h_unsignedp}, {'o', h_oct}, {'x', h_hedec},
		{'X', h_hexU}, {'p', h_ptr}, {'S', h_immprint},
		{'r', h_rev}, {'R', rot_string}, {'\0', NULL}
	};
	for (; fmt_types[k].fmt != '\0'; k++)
		if (fmt[*ind] == fmt_types[k].fmt)
			return (fmt_types[k].fn(list, buffer, flags, width, precision, size));

	if (fmt_types[k].fmt == '\0')
	{
		if (fmt[*ind] == '\0')
			return (-1);
		len += write(1, "%%", 1);
		if (fmt[*ind - 1] == ' ')
			len += write(1, " ", 1);
		else if (width)
		{
			--(*ind);
			while (fmt[*ind] != ' ' && fmt[*ind] != '%')
				--(*ind);
			if (fmt[*ind] == ' ')
				--(*ind);
			return (1);
		}
		len += write(1, &fmt[*ind], 1);
		return (len);
	}
	return (printed_char);
}
