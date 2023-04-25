#include "main.h"
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

void write_content(char buffer[], int *index);

/**
*  _printf - function produces format
* @format: input value
* @...: extra argument variables
* Return: 0
*/

int _printf(const char *format, ...)
{

	int k, output = 0, output_character = 0;
	int flags, width, precision, size, index = 0;

	va_list argt;
	char buffer[BUFF_SIZE];

	if (format == NULL)
		return (-1);

	va_start(argt, format);

	for (k = 0; format && format[k] != '\0'; k++)
	{
		if (format[k] != '%')
		{
			buffer[index++] = format[k];
			if (index == BUFF_SIZE)
				write_content(buffer, &index);
					output_character++;
		}
		else
		{
			write_content(buffer, &index);
			flags = f_flg(format, &k);
			width = f_wdt(format, &k, argt);
			precision = f_prec(format, &k, argt);
			size = f_sizespecifier(format, &k);
			++k;
			output = h_print(format, &k, argt, buffer,
				flags, width, precision, size);
			if (output == -1)
				return (-1);
			output_character += output;
		}
	}

	write_content(buffer, &index);

	va_end(argt);

	return (output_character);
}

/**
 * write_content - prints the contents of Buffer.
 * @buffer: characters array.
 * @index: Index
 *
 * Return: nothing
 */
void write_content(char buffer[], int *index)
{
	if (*index > 0)
		write(1, &buffer[0], *index);

	*index = 0;
}
