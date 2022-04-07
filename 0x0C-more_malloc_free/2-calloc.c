#include <stdio.h>
#include <stdlib.h>
#include "main.h"

/**
* _calloc - a function that allocates memory for an array, using malloc
* @nmemb: unsigned int
* @size: unsigned int
* Return: pointer to allocated memory of NULL if it fails
**/

void *_calloc(unsigned int nmemb, unsigned int size)
{
	char *p;
	unsigned int i;

	if (nmemb == 0 || size == 0)
		return (NULL);
	p = malloc(size * nmemb);
	if (p == NULL)
		return (NULL);
	for (i = 0; i < nmemb * size; i += 1)
		*(p + i) = 0;
	return (p);
}
