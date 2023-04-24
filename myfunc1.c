#include "main.h"
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

/**
 * h_unsignedp - function prints unsigned numbers
 * @types: arguments
 * @buffer: buffer
 * @flags:  flags
 * @width: width
 * @precision: precision
 * @size: size
 * Return: number
 */
int h_unsignedp(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	int t = BUFF_SIZE - 2;
	unsigned long int unsnum = va_arg(types, unsigned long int);

	unsnum = u_r_to_unsg(unsnum, size);

	if (unsnum == 0)
		buffer[t--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (unsnum > 0)
	{
		buffer[t--] = (unsnum % 10) + '0';
		unsnum /= 10;
	}

	t++;

	return (p_unsd(0, t, buffer, flags, width, precision, size));
}
/**
 * h_oct - print unsigned number in octal notation
 * @types: arguments
 * @width: width
 * @buffer: buffer
 * @flags: flags
 * @size: size
 * @precision: precision
 * Return: unsigned nu.s (octal)
 */
int h_oct(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{

	int o = BUFF_SIZE - 2;
	unsigned long int oct_num = va_arg(types, unsigned long int);
	unsigned long int octl_num = oct_num;

	UNUSED(width);

	oct_num = u_r_to_unsg(oct_num, size);

	if (oct_num == 0)
		buffer[o--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (oct_num > 0)
	{
		buffer[o--] = (oct_num % 8) + '0';
		oct_num /= 8;
	}

	if (flags & FLAG_SH && octl_num != 0)
		buffer[o--] = '0';

	o++;

	return (p_unsd(0, o, buffer, flags, width, precision, size));
}
/**
 * h_hedec - function prints in hexadecimal.
 * @types: arguments
 * @buffer: buffer
 * @precision: precision
 * @size: size
 * @width: width
 * @flags: flags
 * Return: hexadecimal no.
 */
int h_hedec(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	return (h_hedexim(types, "0123456789abcdef", buffer,
		flags, 'x', width, precision, size));
}
/**
 * h_hexU - prints in upper hexadecimal notation.
 * @types: argument
 * @width: width
 * @flags: flags
 * @precision: precision
 * @buffer: buffer
 * @size: size
 * Return: no. (upper hexad’)
 */

int h_hexU(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	return (h_hedexim(types, "0123456789ABCDEF", buffer,
		flags, 'X', width, precision, size));
/* function calls h_hedexim function*/
}

/**
 * h_hedexim - prints hexadecimal
 * @types: arguments
 * @map_to: Array of values to map the number to
 * @buffer: buffer
 * @flags: flags
 * @flag_ch: flags
 * @width: width
 * @precision: precision
 * @size: size
 *
 * Return: Hexa no
 */
int h_hedexim(va_list types, char map_to[], char buffer[],
	int flags, char flag_ch, int width, int precision, int size)
{
	int h = BUFF_SIZE - 2;
	unsigned long int hexanum = va_arg(types, unsigned long int);
	unsigned long int mynum = hexanum;

	UNUSED(width);

	hexanum = u_r_to_unsg(hexanum, size);

	if (hexanum == 0)
		buffer[h--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (hexanum > 0)
	{
		buffer[h--] = map_to[hexanum % 16];
		hexanum /= 16;
	}

	if (flags & FLAG_SH && mynum != 0)
	{
		buffer[h--] = flag_ch;
		buffer[h--] = '0';
	}

	h++;

	return (p_unsd(0, h, buffer, flags, width, precision, size));
}
