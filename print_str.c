#include "main.h"

/**
 * p_string - Prints a string
 * @types: args a of arguments
 * @buffer: Buffer array to handle print
 * @flags:  finds if a flag specifier is active
 * @width:  width.
 * @precision: Precision 
 * @size: Size 
 * Return: Number of chars printed
 */
int p_string(va_list types, char buffer[], int flags, int width, int precision, int size)
{
    int length = 0, i;
    char *str = va_arg(types, char *);

    UNUSED(buffer);
    UNUSED(flags);
    UNUSED(width);
    UNUSED(precision);
    UNUSED(size);
    if (str == NULL)
    {
        if (precision >= 6)
        { 
            str = "      ";
        }
        str = "(null)";
      
    }

    while (str[length] != '\0')
        length++;

    if (precision >= 0 && precision < length)
        length = precision;

    if (width > length)
    {
        if (flags & F_MINUS)
        {
            write(1, &str[0], length);
            for (i = width - length; i > 0; i--)
                write(1, " ", 1);
            return (width);
        }
        else
        {
            for (i = width - length; i > 0; i--)
                write(1, " ", 1);
            write(1, &str[0], length);
            return (width);
        }
    }

    return (write(1, str, length));
}