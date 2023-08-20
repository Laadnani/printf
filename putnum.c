#include "main.h"

/**
 * printnum - functions that prints the numbers
 * @num: numbers to be printed
 * Return: number to print
 */

int printnum(int num)
{
	char *i, temp;
	int numval, len, count, len3, len4 = 0;
	int len2 = 0;

	i = malloc(sizeof(int) * 12);

	if (i)
	{
		if (num)
		{
			if (num < 0)
			{
				i[0] = '-';
				num *= -1;
			}
			else
			{
				if (num == 0)
					i[0] = '0';
					i[1] = '\0';
			}
			do {
				numval = num % 10;
				i[count] = numval + '0';
				num = num / 10;
				count++;
			} while (num != 0);
				i[count] = '\0';
				len = count - 1;
			if (i[0] == '-')
				len2 += 1;
			for (len3 = len2; len3 < len; len3++)
				temp = i[len3];
				i[len3] = i[len];
				i[len] = temp;
				len--;
		len4 += _puts(i);
		free(i);
		return (len4);
}
