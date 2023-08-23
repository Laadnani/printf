#include "main.h"

/**
* get_size - Calculates the size to cast the argument
* @format: Formatted string where the argument will be printed
* @i: arguments to be printed.
* Return: Precision.
*/
int get_size(const char *format, int *i)
{
int next_index = *i + 1;
int size = 0;

if (format[next_index] == 'l')
size = S_LONG;
else if (format[next_index] == 'h')
size = S_SHORT;

if (size == 0)
*i = next_index - 1;
else
*i = next_index;

return (size);
}
