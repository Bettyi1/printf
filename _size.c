#include "main.h"
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

/**
 * get_size - determine
 * @format: string containing format
 * @i: arguments pointer
 *
 * Return: size.
 */
int get_size(const char *format, int *i)
{
	int k = *i + 1;
	int size = 0;

	if (format[k] == 'l')
		size = S_LONG;
	else if (format[k] == 'h')
		size = S_SHORT;

	if (size == 0)
		*i = k - 1;
	else
		*i = k;

	return (size);
}

