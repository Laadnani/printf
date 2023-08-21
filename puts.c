#include "main.h"
#include <stdlib.h>

/**
 * _puts - prints strings
 * @str: pointer to the string
 * Return: returning i index
 */

int _puts(char *str)
{
	int i = 0;
	
	if (str == NULL)
	{
		_puts("null");
		return (i);
	}
	while (str[i] != '\0')
	{
		_putchar(str[i]);
		i++;
	}
	i++;
	return (i);
}
