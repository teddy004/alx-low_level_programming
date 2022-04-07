#include <stdio.h>
#include <stdlib.h>
#include "main.h"

/**
* _realloc - a function that reallocates a memory block using malloc and free
* @ptr: is a pointer to the memory previously allocated
* @old_size: is the size, in bytes, of the allocated space for ptr
* @new_size: is the new size, in bytes of the new memory block
* Return: a pointer
**/

void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	void *p;
	unsigned int i;

	i = 0;
	if (new_size == old_size)
		return (ptr);
	if (ptr == NULL)
		return (malloc(new_size));
	if (new_size == 0 && ptr != NULL)
	{
		free(ptr);
		return (NULL);
	}
	p = malloc(new_size);
	if (p == NULL)
		return (NULL);
	if (new_size < old_size)
		old_size = new_size;
	while (i < old_size)
	{
		*((char *)p + i) = *((char *)ptr + i);
		i += 1;
	}
	free(ptr);
	return (p);
}
