#include "main.h"
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

/**
 * f_sizespecifier - determine
 * @format: string containing format
 * @i: arguments pointer
 *
 * Return: size.
 */
int f_sizespecifier(const char *format, int *i)
{
	int k = *i + 1;
	int size = 0;

	if (format[k] == 'l')
		size = L_SIZE;
	else if (format[k] == 'h')
		size = SHORT_SIZE;

	if (size == 0)
		*i = k - 1;
	else
		*i = k;

	return (size);
}
