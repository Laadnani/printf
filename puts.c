#include "main.h"
#include <stdlib.h>

/**
 * _puts - prints strings
 * @str: pointer to the string
 */

void _puts(char *str)
{
	int i = 0;

	while (str[i] != '\0')
	{
		_putchar(str[i]);
		i++;
	}
}
