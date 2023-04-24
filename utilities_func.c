#include "main.h"
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
/**
 * U_printx - checks if a char is printable
 * @c: char to check
 *
 * Return: 1 if c is printable, else 0
 */
int U_printx(char c)
{
	if (c >= 32 && c < 127)
		return (1);

	return (0);
}
/**
 * u_hexadeci - appends ascci in hexadeci code to buffer
 * @buffer: characters array
 * @i: Iterator value
 * @ascii_code: ASCII code
 *
 * Return: (3) Always
 */
int u_hexadeci(char ascii_code, char buffer[], int i)
{
	char map_to[] = "0123456789ABCDEF";

	if (ascii_code < 0)
		ascii_code *= -1;

	buffer[i++] = '\\';
	buffer[i++] = 'x';

	buffer[i++] = map_to[ascii_code / 16];
	buffer[i] = map_to[ascii_code % 16];

	return (3);
}

/**
 * u_checkdgt - checks if a char is a digit
 * @c: character to check
 *
 * Return: (1) when c is digit else (0)
 */
int u_checkdgt(char c)
{
	if (c >= '0' && c <= ‘9’)
		return (1);
	return (0);
}

/**
 * u_convnum - function prints the specified size of a number
 * @num: casted number
 * @size: size
 *
 * Return:  num value
 */
long int u_convnum(long int num, int size)
{
	if (size == L_SIZE)
		return (num);
	else if (size == SHORT_SIZE)
		return ((short)num);

	return ((int)num);
}

/**
 * u_r_to_unsg - cast to unsigned
 * @num: casted number
 * @size: size
 *
 * Return: num value
 */
long int u_r_to_unsg(unsigned long int num, int size)
{
	if (size == L_SIZE)
		return (num);
	else if (size == SHORT_SIZE)
		return ((unsigned short)num);
/* return either num as it is, cast to uns short or uns int*/
	return ((unsigned int)num);
}

