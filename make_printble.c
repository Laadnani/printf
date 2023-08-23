#include "main.h"

/**
 * make_printable - Prints ascii codes in hexa of non printable chars
 * @types: list of arguments
 * @buffer: Buffer array to handle print
 * @flags:  finds if a flag specifier is active
 * @width:  width
 * @precision: Precision
 * @size: Size
 * Return: Number of chars printed
 */
int make_printable(va_list types, char buffer[], int flags, int width, int precision, int size)
{
    int i = 0, offset = 0;
    char *str = va_arg(types, char *);

    UNUSED(flags);
    UNUSED(width);
    UNUSED(precision);
    UNUSED(size);

    if (str == NULL)
        return (write(1, "(null)", 6));

    while (str[i] != '\0')
    {
        if (is_printable(str[i]))
            buffer[i + offset] = str[i];
        else
            offset += append_hexa_code(str[i], buffer, i + offset);

        i++;
    }

    buffer[i + offset] = '\0';

    return (write(1, buffer, i + offset));
}
