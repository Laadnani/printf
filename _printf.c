#include <main.h>

/**
 *
 *
 */
int _printf(char *format, ...)
{
	char str;
	int i, j;
	
	va_list(args);
	va_start(args; format);
	for(i = 0; format[i] != '\0'; i++ )
	{
		while(format[i] != '%')
		{	
			_putchar(format[i]);
			i++;
		}
		i + 1;
		switch(format[i])
		{
		case "c":	j = va_arg(args, int);
				_putchar(j);
				break;
		case "s":	str = va_arg(args, char);
				_puts(str);
				break;
		case "d":
		case "i":	j = va_arg(args, int);
				_printnum(format[i]);
				break;
		}
	}
	va_end;
	return (i);
}
