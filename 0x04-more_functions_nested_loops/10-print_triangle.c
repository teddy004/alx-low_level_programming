#include "main.h"

/**
 * print_triangle - prints a triangle
 * @size: size of triangle
 * Return: nothing
 */

void print_triangle(int size)
{
	int l, c, s;

	if (size <= 0)
	{
		_putchar('\n');
	}
	for (l = 0; l < size; l++)
	{
		for (c = 0; c < size; c++)
		{
			s = size - l - 1;
			if (c < s)
			{
				_putchar(' ');
			}
			else
				_putchar('#');
		}
		_putchar('\n');
	}
}
