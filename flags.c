#include "main.h"

/**
* get_flags - cheking the if the char after % is a flag using bitmask
* @format: Formatted string where the arguments will be printed
* @i: take a parameter.
* Return: Flags if found
*/
int get_flags(const char *format, int *i)
{
const char _char[] = "-+0# ";
const int _val[] = {F_MINUS, F_PLUS, F_ZERO, F_HASH, F_SPACE};

int flags = 0;
int next_index = *i + 1;

while (format[next_index] != '\0')
{
int j;
for (j = 0; _char[j]; j++)
{
if (format[next_index] == _char[j])
{
flags |= _val[j];
break;
}
}
if (_char[j] == '\0')
{
break;
}

next_index++;
}

*i = next_index - 1;

return (flags);
}
