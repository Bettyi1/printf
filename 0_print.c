#include "main.h"
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

void print_buffer(char buffer[], int *index);

/**
* _printf - function produces format
*@format: input value
*@...: extra argument variables
*
* Return: 0
*/

int _printf(const char *format, ...)
{

int k, printed = 0, printed_chars = 0;
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
				print_buffer(buffer, &index);
			printed_chars++;
		}
		else
	{
			print_buffer(buffer, &index);
			flags = get_flags(format, &k);
			width = get_width(format, &k, argt);
			precision = get_precision(format, &k, argt);
			size = get_size(format, &k);
			++k;
			printed = handle_print(format, &k, argt, buffer,
				flags, width, precision, size);
			if (printed == -1)
				return (-1);
			printed_chars += printed;
		}
	}

	print_buffer(buffer, &index);

	va_end(argt);

	return (printed_chars);
}
/**
 * print_buffer - prints the contents of Buffer.
 * @buffer: characters array.
 * @index: Index
 *
 * Return: nothing
 */
void print_buffer(char buffer[], int *index)
{
	if (*index > 0)
		write(1, &buffer[0], *index);

	*index = 0;
}
