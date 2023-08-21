#include "main.h"

/**
 * _printf - printf function mimic
 * @format: format of the selector
 *
 * Return: returning the int i
 */
int _printf(const char *format, ...)
{
	char *str;
	int len = 0;
	int i, j;

	va_list(args);
	va_start(args, format);

	if (!format || !format[0])
	{
		return (0);
	}
	for (i = 0; format[i]; i++)
	{
		while (format[i] != '%')
		{
			if (!format[i])
			{
				return (i);
			}
			len += _putchar(format[i]);
			i++;
		}
		i++;
		switch (format[i])
		{
		case 'c':
			j = va_arg(args, int);
			len += _putchar(j);
			break;
		case 's':
			str = va_arg(args, char*);
			len += _puts(str);
			break;
		case 'i':
		case 'd':
			j = va_arg(args, int);
			len += printnum(j);
			break;
		case '%':
			_putchar(37);
			len++;
			break;
		default:
			_putchar(37);
			_putchar(format[i]);
			len += 1;
			break;
		}
	}
	va_end(args);
	return (len);
}
