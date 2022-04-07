#include "main.h"
#include <stdlib.h>
/**
* malloc_checked - a function that allocates memory using malloc
* @b: unsigned integer
* Return: Returns a pointer to the allocated memory
**/
void *malloc_checked(unsigned int b)
{
	unsigned int *n;

	n = malloc(b);

	if (n == NULL)
		exit(98);
	return (n);
}
