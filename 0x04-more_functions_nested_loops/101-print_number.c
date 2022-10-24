#include "main.h"
#include "stdio.h"

/**
 * print_number - prints an integer
 * @n: the integer to print
 */
void print_number(int n)
{
	int i;
	int max;
	int minVal = n + 1 == -2147483640 - 7 ? -1 : 0;
	int rem = n < 0 ? 0 - n + minVal : n;

	max = 1;
	max *= 100000;
	max *= 100000;

	if (n < 0)
		_putchar('-');

	for (i = 9; i >= 0; i--)
	{
		int power = b10_pow(i);

		if (rem > power - 1 && !(i == 0 && minVal < 0))
			_putchar((int)((rem / power) % 10) + '0');
		else if (i == 0 && minVal >= 0)
			_putchar((int)((rem / power) % 10) + '0');
		if (i == 0 && minVal < 0)
			_putchar('8');
	}
}

/**
 * b10_pow - Computes the power of 10 to the given index
 * @idx: The index to which 10 is raised to.
 *
 * Return: A power of 10
 */
int b10_pow(int idx)
{
	int i;
	int result = 1;

	if (idx < 0)
		return (0);

	for (i = 0; i < idx; i++)
	{
		result *= 10;
	}
	return (result);
}
