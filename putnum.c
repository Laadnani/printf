#include "main.h"

void printnum(int num)
{
	if(num < 0)
	{
		_putchar('-');
		num = -num;
	}
	if(num / 10)
	printnum(num / 10);
	_putchar((num % 10) + '0');
}
