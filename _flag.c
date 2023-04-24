#include "main.h"
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

/**
 * f_flg - returns set flag
 * @format: pointer to format
 * @i: iterator value
 * Return: flags
 */
int f_flg(const char *format, int *i)
{
	int a;
int b;
	int flags = 0;
	const char FLAGS_CH[] = {'-', '+', '0', '#', ' ', '\0'};
	const int FLAGS_ARR[] = {FLAG_S, FLAG_A, FLAG_O, FLAG_SH, FLAG_P, 0};

	for (b = *i + 1; format[b] != '\0'; b++)
	{
		for (a = 0; FLAGS_CH[a] != '\0'; a++)
			if (format[b] == FLAGS_CH[a])
			{
				flags |= FLAGS_ARR[a];
				break;
			}

		if (FLAGS_CH[a] == 0)
			break;
	}

	*i = b - 1;

	return (flags);
}
