#include "main.h"
/**
 * to_print - Prints an argument if the type is found
 * @ft: string handled char by char 
 * @args: type of arguments to be printed.
 * @ind: index
 * @buffer: Buffer array to handle print.
 * @flags: finds if a flag specifier is active
 * @width: width
 * @precision: Precision 
 * @size: Size 
 * Return: function found to format the string specifier or the char following % or -1 if none found ;
 */
int to_print(const char *ft, int *ind, va_list args, char buffer[], int flags, int width, int precision, int size)
{
    int i, starting_at = 0;
    fmt_t fmt_types[] = {
        {'c', p_char},
        {'s', p_string}, 
        {'%', p_percent}, 
        {'i', p_int}, 
        {'d', p_int}, 
        {'b', p_binary}, 
        {'u', p_unsigned}, 
        {'o', p_octal},
        {'x', p_hexadecimal}, 
        {'X', p_hexa_upper}, 
        {'p', p_pointer}, 
        {'S', make_printable}, 
        {'r', p_rev},
        {'R', p_rot13string}, 
        {'\0', NULL}};
    for (i = 0; fmt_types[i].ft != '\0'; i++)
        if (ft[*ind] == fmt_types[i].ft)
            return (fmt_types[i].func(args, buffer, flags, width, precision, size));

    if (fmt_types[i].ft == '\0')
    {
        if (ft[*ind] == '\0')
            return (-1);
        starting_at += write(1, "%%", 1);
        if (ft[*ind - 1] == ' ')
            starting_at += write(1, " ", 1);
        else if (width)
        {
            --(*ind);
            while (ft[*ind] != ' ' && ft[*ind] != '%')
                --(*ind);
            if (ft[*ind] == ' ')
                --(*ind);
            return (1);
        }
        starting_at += write(1, &ft[*ind], 1);
        return (starting_at);
    }
    return (-1);
}
