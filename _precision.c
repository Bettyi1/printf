#include "main.h"
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

/**
 * get_precision - determine and precision
 * @format: pointer to formats
 * @i: Arguments input
 * @list: Arguments input
 *
 * Return: Precision.
 */
int get_precision(const char *format, int *i, va_list list)
{
	int x = *i + 1;
	int prec = -1;

	if (format[x] != '.')
		return (prec);

	prec = 0;

	for (x += 1; format[x] != '\0'; x++)
	{
		if (is_digit(format[x]))
		{
			prec *= 10;
			prec += format[x] - '0';
		}
		else if (format[x] == '*')
		{
			x++;
			prec = va_arg(list, int);
			break;
		}
		else
			break;
	}

	*i = x - 1;

	return (prec);
}
