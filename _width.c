#include "main.h"
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

/**
 * f_wdt - determine and print width
 * @format: string with format.
 * @i: arguments to print
 * @list: input arguments
 *
 * Return: width.
 */

int f_wdt(const char *format, int *i, va_list list)
{
	int j;
	int width = 0;

	for (j = *i + 1 ; format[j] != '\0' ; j++)
	{
		if (u_checkdgt(format[j]))
		{
			width *= 10;
			width += format[j] - '0';
		}
		else if (format[j] == '*')
		{
			j++;
			width = va_arg(list, int);
			break;
		}
		else
			break;
	}

	*i = j - 1;

	return (width);
}

