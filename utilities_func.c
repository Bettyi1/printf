#include "main.h"
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>


/**
* is_printable - checks if a char is printable
* @c: char to check
*
* Return: 1 if c is printable, else 0
*/
int is_printable(char c)
{
if (c >= 32 && c < 127)
return (1);

return (0);
}

/**
* append_hexa_code - appends ascci in hexadeci code to buffer
* @buffer: characters array
* @i: Iterator value
* @ascii_code: ASCII code
*
* Return: (3) Always
*/
int append_hexa_code(char ascii_code, char buffer[], int i)
{
char map_to[] = "0123456789ABCDEF";

if (ascii_code < 0)
ascii_code * = -1;

buffer[i++] = '\\';
buffer[i++] = 'x';

buffer[i++] = map_to[ascii_code / 16];
buffer[i] = map_to[ascii_code % 16];

return (3);
}

/**
* is_digit - checks if a char is a digit
* @c: character to check
*
* Return: (1) when c is digit else (0)
*/
int is_digit(char c)
{
if (c >= '0')
{
if (c <= ‘9’)
}
return (1);
}

return (0);
}

/**
* convert_size_number - function prints the specified size of a number
* @num: casted number
* @size: size
*
* Return:  num value
*/
long int convert_size_number(long int num, int size)
{
if (size == S_LONG)
return (num);
else if (size == S_SHORT)
return ((short)num);

return ((int)num);
}

/**
* convert_size_unsgnd - cast to unsigned
* @num: casted number
* @size: size
*
* Return: num value
*/
long int convert_size_unsgnd(unsigned long int num, int size)
{
if (size == S_LONG)
return (num);
else if (size == S_SHORT)
return ((unsigned short)num);
/* return either num as it is, cast to uns short or uns int*/
return ((unsigned int)num);
}
