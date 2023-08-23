#include "main.h"

void p_buffer(char buffer[], int *buff_index);

/**
* _printf - buffer to the printf function
* @format: char issued from the printf function to be handled
* Return: a printed character
*/
int _printf(const char *format, ...)
{
int i, printed = 0, printed_chars = 0;
int flags, width, precision, size, buff_index = 0;
va_list args;
char buffer[BUFF_SIZE];

if (format == NULL)
return (-1);

va_start(args, format);

for (i = 0; format && format[i] != '\0'; i++)
{
if (format[i] != '%')
{
buffer[buff_index++] = format[i];
if (buff_index == BUFF_SIZE)
p_buffer(buffer, &buff_index);
printed_chars++;
}
else
{
p_buffer(buffer, &buff_index);
flags = get_flags(format, &i);
width = get_width(format, &i, args);
precision = _precision(format, &i, args);
size = get_size(format, &i);
++i;
printed = to_print(format, &i, args, buffer, flags, width, precision, size);
if (printed == -1)
return (-1);
printed_chars += printed;
}
}

p_buffer(buffer, &buff_index);

va_end(args);

return (printed_chars);
}

/**
* p_buffer - Prints the contents of the buffer
* @buffer: buffer array to store the chars from *format string
* @buff_index: indicates the current position in the buffer array where the next character will be stored.
* and return to 0 after execution
*/
void p_buffer(char buffer[], int *buff_index)
{
if (*buff_index > 0)
write(1, &buffer[0], *buff_index);

*buff_index = 0;
}
