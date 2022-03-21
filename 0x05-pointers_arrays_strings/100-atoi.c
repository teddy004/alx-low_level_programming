#include "main.h"
#include <stdio.h>

/**
 * _atoi - converests a string to an integer
 * @s: string to convert
 * Return: numbre
 */


int _atoi(char *s)
{
	int n, i, m;

	m = 1;
	i = n = 0;
	while ((s[i] < '0' || s[i] > '9') && s[i] != 0)
	{
		if (s[i] == '-')
			m = m * -1;
		i++;
	}
	while ((s[i] >= '0' && s[i] <= '9') && s[i] != 0)
	{
		if (n >= 0)
		{
			n = n * 10 - (s[i] - '0');
			i++;
		}
		else
		{
			n = n * 10 - (s[i] - '0');
			i++;
		}
	}
	m = m * -1;
	return (n * m);
}
