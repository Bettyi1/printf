#include "main.h"
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

/**
* print_character23 - function prints a char
* @types: arguments
* @width: Width
* @precision: precision specification
* @flags: flags
* @size: size
* @buffer: buffer array
* Return: chars to be printed
*/

int print_character23(va_list types, char buffer[],
int flags, int width, int precision, int size)
{
char c = va_arg(types, int);

return (p_character(c, buffer, flags, width, precision, size));
}

/**
* h_stringp - prints a string to stdout
* @types: arguments
* @buffer: buffer
* @flags: flags
* @width: width.
* @precision: precision
* @size: size
*
* Return: characters
*/

int h_stringp(va_list types, char buffer[],
int flags, int width, int precision, int size)
{
int length = 0, x;
char *str = va_arg(types, char *);

UNUSED(buffer);
UNUSED(flags);
UNUSED(width);
UNUSED(precision);
UNUSED(size);
if (str == NULL)
{
str = "(null)";
if (precision >= 6)
str = "      ";
}
while (str[length] != '\0')
length++;
if (length > precision && precision >= 0)
length = precision;

if (length < width)
{
if (flags & FLAG_S)
{
write(1, &str[0], length);
for (x = width - length; x > 0; x--)
write(1, " ", 1);
return (width);
}
else
{
for (x = width - length; x > 0; x--)
write(1, " ", 1);
write(1, &str[0], length);
return (width);
}
}
return (write(1, str, length));
}
/**
* _percenthandler - function prints a percent sign
* @buffer: buffer array
* @types: arguments
* @flags: counts active flags
* @precision: precision
* @size: size
* @width: get width.
* Return: char
*/
int _percenthandler(va_list types, char buffer[],
int flags, int width, int precision, int size)
{

UNUSED(buffer);
UNUSED(types);
UNUSED(flags);
UNUSED(precision);
UNUSED(size);
UNUSED(width);
return (write(1, "%%", 1));
}


/**
* h_intr - function prints integers
* @types: Arguments.
* @buffer: buffer
* @flags: flags
* @width: width.
* @precision: precision
* @size: size
*
* Return: integer printed
*/
int h_intr(va_list types, char buffer[],
int flags, int width, int precision, int size)
{
int j = BUFF_SIZE - 2;
unsigned long int num;
int is_negative = 0;
long int y = va_arg(types, long int);


y = u_convnum(y, size);

if (y == 0)
buffer[j--] = '0';

buffer[BUFF_SIZE - 1] = '\0';
num = (unsigned long int)y;

if (y < 0)
{
num = (unsigned long int)((-1) * y);
is_negative = 1;
}

while (num > 0)
{
buffer[j--] = (num % 10) + '0';
num /= 10;
}

j++;

return (p_wnumbr(is_negative, j, buffer, flags, width, precision, size));
}

/**
* h_binary - function prints unsigned numbers
* @types: arguments
* @buffer: buffer array
* @flags:  active flags
* @width: input value.
* @precision: input value
* @size: sizer
* Return: char to be printed
*/
int h_binary(va_list types, char buffer[],
int flags, int width, int precision, int size)
{
unsigned int sum, y, i, x;
unsigned int myarr[32];
int count;

UNUSED(buffer);
UNUSED(flags);
UNUSED(width);
UNUSED(precision);
UNUSED(size);

x = va_arg(types, unsigned int);
y = 2147483648;
myarr[0] = x / y;
for (i = 1; i < 32; i++)
{
y /= 2;
myarr[i] = (x / y) % 2;
}
for (i = 0, sum = 0, count = 0; i < 32; i++)
{
sum += myarr[i];
if (sum || i == 31)
{
char z = '0' + myarr[i];

write(1, &z, 1);
count++;
}
}
return (count);
}
