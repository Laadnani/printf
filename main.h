#ifndef MAIN_H
#define MAIN_H

#include <limits.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdarg.h>
#include <unistd.h>

/**
 * struct ft - Struct op
 *
 * @ft: The format.
 * @func: The function associated.
 */
typedef struct alloc
{
    char ft;
    int (*func)(va_list, char[], int, int, int, int);
} fmt_t;

#define UNUSED(x) (void)(x)
#define BUFF_SIZE 1024
#define F_MINUS 1
#define F_PLUS 2
#define F_ZERO 4
#define F_HASH 8
#define F_SPACE 16
#define S_LONG 2
#define S_SHORT 1

int _printf(const char *format, ...);
int to_print(const char *ft, int *i, va_list args, char buffer[], int flags, int width, int precision, int size);
long int convert_size_number(long int num, int size);
long int convert_size_unsgnd(unsigned long int num, int size);
int p_int(va_list types, char buffer[], int flags, int width, int precision, int size);
int p_binary(va_list types, char buffer[], int flags, int width, int precision, int size);
int p_unsigned(va_list types, char buffer[], int flags, int width, int precision, int size);
int p_octal(va_list types, char buffer[], int flags, int width, int precision, int size);
int p_hexadecimal(va_list types, char buffer[], int flags, int width, int precision, int size);
int p_hexa_upper(va_list types, char buffer[], int flags, int width, int precision, int size);
int p_char(va_list types, char buffer[],int flags, int width, int precision, int size);
int p_string(va_list types, char buffer[], int flags, int width, int precision, int size);
int p_percent(va_list types, char buffer[], int flags, int width, int precision, int size);
int p_hexa(va_list types, char map_to[], char buffer[], int flags, char flag_ch, int width, int precision, int size);
int make_printable(va_list types, char buffer[], int flags, int width, int precision, int size);
int p_pointer(va_list types, char buffer[], int flags, int width, int precision, int size);
int get_flags(const char *format, int *i);
int get_width(const char *format, int *i, va_list args);
int _precision(const char *format, int *i, va_list args);
int get_size(const char *format, int *i);
int p_rev(va_list types, char buffer[], int flags, int width, int precision, int size);
int p_rot13string(va_list types, char buffer[], int flags, int width, int precision, int size);
int handle_write_char(char c, char buffer[], int flags, int width, int precision, int size);
int write_number(int is_positive, int ind, char buffer[], int flags, int width, int precision, int size);
int write_num(int ind, char bff[], int flags, int width, int precision,  int length, char padd, char extra_c);
int write_pointer(char buffer[], int ind, int length, int width, int flags, char padd, char extra_c, int padd_start);
int write_unsgnd(int is_negative, int ind, char buffer[], int flags, int width, int precision, int size);
int append_hexa_code(char, char[], int);

int is_digit(char);
int is_printable(char);

#endif
