#include <unistd.h>
#include "main.h"

/**
 * _putchar - returning the ASCII value
 * @c: character value
 * Return: int value
 */

int _putchar(char c)
{
	if (!c)
	{
		return(write(1, "\\0", 1));
	}
	else 
	{
	return (write(1, &c, 1));
	}
	return(-1);
}
