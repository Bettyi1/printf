#include "main.h"
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
/**
 * p_character - function prints a string
 * @buffer: buffer array
 * @flags:  checks active flags
 * @width: get width.
 * @precision: precision
 * @c: char type
 * @size: size
 *
 * Return: number of chars
 */
int p_character(char c, char buffer[],
	int flags, int width, int precision, int size)
{
	int k = 0;
	char space = ' ';

	UNUSED(precision);
	UNUSED(size);

	if (flags & FLAG_O)
		space = '0';

	buffer[k++] = c;
	buffer[k] = '\0';

	if (width > 1)
	{
		buffer[BUFF_SIZE - 1] = '\0';
		for (k = 0; k < width - 1; k++)
			buffer[BUFF_SIZE - k - 2] = space;

		if (flags & FLAG_S)
			return (write(1, &buffer[0], 1) +
					write(1, &buffer[BUFF_SIZE - k - 1], width - 1));
		else
			return (write(1, &buffer[BUFF_SIZE - k - 1], width - 1) +
					write(1, &buffer[0], 1));
	}

	return (write(1, &buffer[0], 1));
}

/**
 * p_wnumbr - function prints a string
 * @is_negative: arguments
 * @buffer: buffer array
 * @flags:  flags
 * @width: width.
 * @precision: precision
 * @ind: char
 * @size: size
 *
 * Return: char
 */
int p_wnumbr(int is_negative, int ind, char buffer[],
	int flags, int width, int precision, int size)
{
	int length = BUFF_SIZE - ind - 1;
	char space = ' ';
char zeros = 0;

	UNUSED(size);

	if ((flags & FLAG_O) && !(flags & FLAG_S))
		space = '0';
	if (is_negative)
		zeros = '-';
	else if (flags & FLAG_A)
		zeros = '+';
	else if (flags & FLAG_P)
		zeros = ' ';

	return (p_num(ind, buffer, flags, width, precision,
		length, space, zeros));
}

/**
 * p_num - function writes a number using buffer
 * @buffer: buffer
 * @flags: flags
 * @ind: index
 * @width: width
 * @prec: precision
 * @space: space char
 * @length: length
 * @zeros: extra char
 * Return: Number of printed chars.
 */
int p_num(int ind, char buffer[],
	int flags, int width, int prec,
	int length, char space, char zeros)
{
	int k, space_start = 1;

	if (prec == 0 && ind == BUFF_SIZE - 2 && buffer[ind] == '0' && width == 0)
		return (0);
	if (prec == 0 && ind == BUFF_SIZE - 2 && buffer[ind] == '0')
		buffer[ind] = space = ' ';
	if (prec > 0 && prec < length)
		space = ' ';
	while (prec > length)
		buffer[--ind] = '0', length++;
	if (zeros != 0)
		length++;
	if (length < width)
	{
		for (k = 1 ; k < width - length + 1 ; k++)
			buffer[k] = space;
		buffer[k] = '\0';
		if (flags & FLAG_S && space == ' ')
		{
			if (zeros)
				buffer[--ind] = zeros;
			return (write(1, &buffer[ind], length) + write(1, &buffer[1], k - 1));
		}
		else if (!(flags & FLAG_S) && space == ' ')
		{
			if (zeros)
				buffer[--ind] = zeros;
			return (write(1, &buffer[1], k - 1) + write(1, &buffer[ind], length));
		}
		else if (!(flags & FLAG_S) && space == '0')
		{
			if (zeros)
				buffer[--space_start] = zeros;
			return (write(1, &buffer[space_start], k - space_start) +
				write(1, &buffer[ind], length - (1 - space_start)));
		}
	}
	if (zeros)
		buffer[--ind] = zeros;
	return (write(1, &buffer[ind], length));
}

/**
 * p_unsd - function prints unsigned num.
 * @is_negative: negative id
 * @ind: iterator
 * @buffer: buffer
 * @flags: flags
 * @width: width
 * @precision: precision
 * @size: size
 *
 * Return: unsigned num.
 */
int p_unsd(int is_negative, int ind,
	char buffer[],
	int flags, int width, int precision, int size)
{
int j = 0;
int len = BUFF_SIZE - ind - 1;
	char space = ' ';

	UNUSED(is_negative);
	UNUSED(size);

	if (precision == 0 && ind == BUFF_SIZE - 2 && buffer[ind] == '0')
		return (0);

	if (precision > 0 && precision < len)
		space = ' ';

	while (len < precision)
	{
		buffer[--ind] = '0';
		len++;
	}

	if ((flags & FLAG_O) && !(flags & FLAG_S))
		space = '0';

	if (len < width)
	{
		for (j = 0 ; j < width - len ; j++)
			buffer[j] = space;

		buffer[j] = '\0';

		if (flags & FLAG_S)
		{
			return (write(1, &buffer[ind], len) + write(1, &buffer[0], j));
		}
		else
		{
			return (write(1, &buffer[0], j) + write(1, &buffer[ind], len));
		}
	}

	return (write(1, &buffer[ind], len));
}

/**
 * p_wptr - prints a pointer
 * @buffer: buffer.
 * @ind: Iterator.
 * @length: length
 * @width: width
 * @flags: flags
 * @space: padding space
 * @zeros: zeros
 * @space_start: padding iterator
 *
 * Return: pointer printed
 */
int p_wptr(char buffer[], int ind, int length,
	int width, int flags, char space, char zeros, int space_start)
{
	int a;

	if (length < width)
	{
		for (a = 3; a < width - length + 3; a++)
			buffer[a] = space;
		buffer[a] = '\0';
		if (flags & FLAG_S && space == ' ')
		{
			buffer[--ind] = 'x';
			buffer[--ind] = '0';
			if (zeros)
				buffer[--ind] = zeros;
			return (write(1, &buffer[ind], length) + write(1, &buffer[3], a - 3));
		}
		else if (!(flags & FLAG_S) && space == ' ')
		{
			buffer[--ind] = 'x';
			buffer[--ind] = '0';
			if (zeros)
				buffer[--ind] = zeros;
			return (write(1, &buffer[3], a - 3) + write(1, &buffer[ind], length));
		}
		else if (!(flags & FLAG_S) && space == '0')
		{
			if (zeros)
				buffer[--space_start] = zeros;
			buffer[1] = '0';
			buffer[2] = 'x';
			return (write(1, &buffer[space_start], a - space_start) +
				write(1, &buffer[ind], length - (1 - space_start) - 2));
		}
	}
	buffer[--ind] = 'x';
	buffer[--ind] = '0';
	if (zeros)
		buffer[--ind] = zeros;
	return (write(1, &buffer[ind], BUFF_SIZE - ind - 1));
}
