#include "main.h"

/**
 * p_percent - Prints a percent sign
 * @types: list of arguments
 * @buffer: Buffer array to handle print
 * @flags:  finds if a flag specifier is active
 * @width:  width.
 * @precision: Precision
 * @size: Size
 * Return: Number of chars printed
 */
int p_percent(va_list types, char buffer[],
                  int flags, int width, int precision, int size)
{
    UNUSED(types);
    UNUSED(buffer);
    UNUSED(flags);
    UNUSED(width);
    UNUSED(precision);
    UNUSED(size);
    return (write(1, "%", 1));
}
