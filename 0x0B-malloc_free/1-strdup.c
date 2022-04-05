#include <stdlib.h>
#include "main.h"

/**
* _strdup - returns apointer to the newly allocated memory
* @str: holds the string
* Return: the pointer
**/

char *_strdup(char *str)
{
	char *p;
	int i;
	int j;

	j = 0;
	i = 0;
	if (str == NULL)
		return (NULL);
	while (str[i])
		i += 1;
	p = malloc(i * sizeof(char) + 1);

	if (p == NULL)
		return (NULL);
	while (*str)
	{
		p[j] = *str;
		str++;
		j += 1;
	}
	p[j] = *str;
		return (p);
}
