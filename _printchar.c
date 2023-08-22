#include "main.h"

/**
 * _printchar - print a character passed as arg
 * @c: char to print
 * Return: count +1 for each char printed
 */

int _printchar(char c)
{
	int count = 0;

	if (!c)
	{
		return (0);
	}
	count += _putchar(c);
	return (count);
}
