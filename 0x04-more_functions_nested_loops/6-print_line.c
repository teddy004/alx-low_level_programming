#include "main.h"

/**
* print_line - draws a straight line in the terminal
* @n: the number of times the character _
* Return: none;
**/

void print_line(int n)
{
	int count;

	for (count = 0; count < n; count++)
	{
		_putchar('_');
	}
	_putchar('\n');
}
