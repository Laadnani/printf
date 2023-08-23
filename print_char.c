#include "main.h"

/************************* PRINT CHAR *************************/

/**
* p_char - Prints a char
* @types: args a of arguments
* @buffer: Buffer array to handle print
* @flags:  finds if a flag specifier is active
* @width: Width
* @precision: Precision 
* @size: Size 
* Return: Number of chars printed
*/
int p_char(va_list types, char buffer[],int flags, int width, int precision, int size)
{
char c = va_arg(types, int);

return (handle_write_char(c, buffer, flags, width, precision, size));
}
