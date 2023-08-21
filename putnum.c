#include "main.h"

/**
 * num_len - return the lenght of the number
 * @num: number to treat
 * Return: lenght of the number treated
 */

int num_len(int num)
{
	if (num == 0)
	{
		return (0);
	}
	return (1 + num_len(num / 10));
}

/**
 * printnum - functions that prints the numbers
 * @num: numbers to be printed
 * Return: count of printed number(s)
 */

int printnum(int num)
{
	int count = 0;

	if (num < 0)
	{
		count++;
	}
	count += num_len(num);
	if (num < 0)
	{
		_putchar('-');
		num = -num;
	}
	if (num >= 10)
	{
		count += printnum(num / 10);
		count += printnum(num % 10);
	}
	else if (num < 10)
	{
		_putchar(num + '0');
	}
	return (count);
}
