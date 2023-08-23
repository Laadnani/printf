#include "main.h"

/**
 * get_width - Calculates the width for printing
 * @format: Formatted string where the argument will be printed
 * @i: arguments to be printed.
 * @args: arguments.
 *
 * Return: width.
 */
int get_width(const char *format, int *i, va_list args)
{
    int next_index;
    int width = 0;

    for (next_index = *i + 1; format[next_index] != '\0'; next_index++)
    {
        if (is_digit(format[next_index]))
        {
            width *= 10;
            width += format[next_index] - '0';
        }
        else if (format[next_index] == '*')
        {
            next_index++;
            width = va_arg(args, int);
            break;
        }
        else
            break;
    }

    *i = next_index - 1;

    return (width);
}
