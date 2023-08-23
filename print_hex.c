#include "main.h"

/**
* p_hexadecimal - Prints an unsigned number in hexadecimal notation
* @types: list of arguments
* @buffer: Buffer array to handle print
* @flags:  finds if a flag specifier is active
* @width:  width
* @precision: Precision
* @size: Size
* Return: Number of chars printed
*/
int p_hexadecimal(va_list types, char buffer[], int flags, int width, int precision, int size)
{
return (p_hexa(types, "0123456789abcdef", buffer, flags, 'x', width, precision, size));
}

/**
* p_hexa_upper - Prints an unsigned number in upper hexadecimal notation
* @types: list of arguments
* @buffer: Buffer array to handle print
* @flags:  finds if a flag specifier is active
* @width:  width
* @precision: Precision
* @size: Size
* Return: Number of chars printed
*/
int p_hexa_upper(va_list types, char buffer[], int flags, int width, int precision, int size)
{
return (p_hexa(types, "0123456789ABCDEF", buffer, flags, 'X', width, precision, size));
}

/**
* p_hexa - Prints a hexadecimal number in lower or upper
* @types: list of arguments
* @map_to: Array of values to map the number to
* @buffer: Buffer array to handle print
* @flags:  finds if a flag specifier is active
* @flag_ch: finds if a flag specifier is active
* @width:  width
* @precision: Precision
* @size: Size
* @size: Size specification
* Return: Number of chars printed
*/
int p_hexa(va_list types, char map_to[], char buffer[], int flags, char flag_ch, int width, int precision, int size)
{
int i = BUFF_SIZE - 2;
unsigned long int num = va_arg(types, unsigned long int);
unsigned long int init_num = num;

UNUSED(width);

num = convert_size_unsgnd(num, size);

if (num == 0)
buffer[i--] = '0';

buffer[BUFF_SIZE - 1] = '\0';

while (num > 0)
{
buffer[i--] = map_to[num % 16];
num /= 16;
}

if (flags & F_HASH && init_num != 0)
{
buffer[i--] = flag_ch;
buffer[i--] = '0';
}

i++;

return (write_unsgnd(0, i, buffer, flags, width, precision, size));
}
