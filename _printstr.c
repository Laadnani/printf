#include "main.h"

/**
 * _printstr - print a string to the console
 * @str: string to be printed
 * Return: count of how many chars printed
 */

int _printstr(char *str)
{
        if(!str)
        {
                str = "(null)";
        }
        return(_puts(str));
}
