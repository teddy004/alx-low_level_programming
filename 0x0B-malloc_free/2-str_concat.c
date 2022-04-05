#include <stdlib.h>
#include "main.h"

/**
* str_concat - a function that concatenates two strings
* @s1: holds the first string
* @s2: holds the second string
* Return: the pointer to a string
**/

char *str_concat(char *s1, char *s2)
{
	int i;
	int j;
	int k;
	char *p;

	i = 0;
	j = 0;
	k = 0;

	if (!s1)
		s1 = "";
	if (!s2)
		s2 = "";
	while (s1[i])
		i += 1;
	while (s2[j])
		j += 1;
	p = malloc((i + j) * sizeof(char) + 1);
	if (p == NULL)
		return (NULL);
	while (*s1)
	{
		p[k] = *s1++;
		k += 1;
	}
	while (*s2)
	{
		p[k] = *s2++;
		k += 1;
	}
	return (p);
}
