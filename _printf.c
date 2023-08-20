#include "main.h"

/**
 * _printf - printf function mimic
 * @format: format of the selector
 *
 * Return: returning the int i
 */
int _printf(char *format, ...)
{
	char *str;
	int i, j;

	va_list(args);
	va_start(args, format);
	for (i = 0; format[i]; i++)
	{
		while (format[i] != '%')
		{
			if (!format[i])
			{
				return (i);
			}
			_putchar(format[i]);
			i++;
		}
		i++;
		switch (format[i])
		{
		case 'c':
			j = va_arg(args, int);
			_putchar(j);
			break;
		case 's':
			str = va_arg(args, char*);
			_puts(str);
			break;
		case 'i':
			j = va_arg(args, int);
			printnum(format[i]);
			break;
		case '%':
			_putchar(37);
			break;
		default:
			j = va_arg(args, int);
			_putchar(j);
			break;
		}
	}
	va_end(args);
	return (i);
}
