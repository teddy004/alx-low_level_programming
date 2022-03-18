#include "main.h"

/**
* print_number - prints the number
* @n: number to print
* Return:none
**/

void print_number(int n)
{
	int i, d, p, f;
	long j;
	char num[1000];

	p = 0;
	f = 0;
	j = n;
	if (j < 0)
	{
		j = j * -1;
		f = 1;
	}
	while ((j / 10) != 0)
	{
		d = j % 10;
		num[p] = d;
		p++;
		j = j / 10;
	}
	num[p] = j;
	if (f == 1)
	{
		p++;
		num[p] = '-';
	}
	for (i = p; i >= 0; i--)
	{
		if (num[i] != '-')
		{
			_putchar(num[i] + '0');
		}
		else
			_putchar('-');
	}
}
