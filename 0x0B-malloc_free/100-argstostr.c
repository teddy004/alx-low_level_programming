#include <stdio.h>
#include <stdlib.h>
#include "main.h"

/**
* argstostr - a function that concatenates all the arguments of your program
* @ac: integer
* @av: string
* Return: Returns a pointer to a new string, or NULL if it fails
**/

char *argstostr(int ac, char **av)
{
	char *p;
	int i;
	int j = 0;
	int k = 0;
	int len;

	if (ac == 0 || av == NULL)
		return (NULL);
	for (i = 0; i < ac; i += 1)
	{
		while (av[i][j] != '\0')
		{
			j += 1;
		}
		len += j;
		j = 0;
	}
	p = malloc(sizeof(char) * len + 1 + ac);

		for (i = 0; i < ac; i += 1)
		{
			while (av[i][j] != '\0')
			{
				p[j + k] = av[i][j];
				j += 1;
			}
			k += j;
			j = 0;
			p[k++] = '\n';
		}
	p[k + 1] = '\0';

	return (p);
}
