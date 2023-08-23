#include "main.h"
/**
* p_rev - Prints reverse string.
* @types: agrguments
* @buffer: Buffer array to handle print
* @flags:  finds if a flag specifier is active
* @width:  width
* @precision: Precision
* @size: Size
* Return: Numbers of chars printed
*/

int p_rev(va_list types, char buffer[], int flags, int width, int precision, int size)
{
char *str;
int i, count = 0;

UNUSED(buffer);
UNUSED(flags);
UNUSED(width);
UNUSED(size);

str = va_arg(types, char *);

if (!str)
{
UNUSED(precision);

str = "(Null)";
}
for (i = 0; str[i]; i++)
	{
	if (str[1] == '\0')
	{
		count += write(1, "%r", 2);
		return (count);
	}
	}

for (i = i - 1; i >= 0; i--)
{
char z = str[i];

write(1, &z, 1);
count++;
}
return (count);
}
