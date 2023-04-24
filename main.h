#ifndef MAIN_H
#define MAIN_H
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

#define UNUSED(x) (void)(x)
#define BUFF_SIZE 1024

/*these are flags defined here*/

#define FLAG_O 4
#define FLAG_P 16
#define FLAG_A 2
#define FLAG_S 1
#define FLAG_SH 8

/* sizes defined*/
#define SHORT_SIZE 1
#define L_SIZE 2

/**
 * struct fmt - struct op
 * @fmt: format abbv.
 * @fn: function called as argument of fmt
 */
struct fmt
{
	char fmt;
	int (*fn)(va_list, char[], int, int, int, int);
};


/**
 * typedef struct fmt fmt_t - new name declaration(fmt_t of type fmt)
 * @fmt: type
 * @fmt_t: new name
 */
typedef struct fmt fmt_t;

int _printf(const char *format, ...);
int h_print(const char *fmt, int *i,
va_list list, char buffer[], int flags, int width, int precision, int size);

/*Utilities function*/
int u_hexadeci(char, char[], int);
int u_checkdgt(char);
int U_printx(char);

/* memory address */
int h_ptr(va_list types, char buffer[],
	int flags, int width, int precision, int size);

/* int, binary, unsigned, octal, hexa_decimal, hexa_upper, hexa functions */
int h_hedec(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int h_binary(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int h_unsignedp(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int h_oct(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int h_hexU(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int h_intr(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int h_hedexim(va_list types, char map_to[],
char buffer[], int flags, char flag_ch, int width, int precision, int size);

/* prints non-printable characters */
int h_immprint(va_list types, char buffer[],
	int flags, int width, int precision, int size);



/* functions handles*/
int f_sizespecifier(const char *format, int *i);
int f_wdt(const char *format, int *i, va_list list);
int f_flg(const char *format, int *i);
int f_prec(const char *format, int *i, va_list list);



/*’r’ - reverse function*/
int h_rev(va_list types, char buffer[],
	int flags, int width, int precision, int size);

/*prints a string for rot 13*/
int rot_string(va_list types, char buffer[],
	int flags, int width, int precision, int size);


/* chars, strings, percent functions */
int _percenthandler(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int print_character23(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int h_stringp(va_list types, char buffer[],
	int flags, int width, int precision, int size);

/* precision*/
int p_wptr(char buffer[], int ind, int length,
	int width, int flags, char space, char zeros, int space_start);
int p_character(char c, char buffer[],
	int flags, int width, int precision, int size);
int p_unsd(int is_negative, int ind,
char buffer[],
	int flags, int width, int precision, int size);
int p_wnumbr(int is_positive, int ind, char buffer[],
	int flags, int width, int precision, int size);
int p_num(int ind, char bff[], int flags, int width, int precision,
	int length, char space, char zeros);





long int u_r_to_unsg(unsigned long int num, int size);
long int u_convnum(long int num, int size);

#endif
