#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lists.h"

/**
* free_listint_safe - frees a linked list safely
* @h: holds a pointer to a pointer of a linked list
* Return: the size of the list
*/

size_t free_listint_safe(listint_t **h)
{
	listint_t *s_ptr, *f_ptr, *free_ptr;
	size_t size;

	size = 0;

	if (!h || *h == NULL)
		return (0);
	f_ptr = (*h)->next;
	s_ptr = *h;

	while (f_ptr && f_ptr < s_ptr)
	{
		free_ptr = s_ptr;
		f_ptr = f_ptr->next;
		s_ptr = s_ptr->next;
		size += 1;

		free(free_ptr);
	}
	size += 1;
	free(s_ptr);
	*h = NULL;
	return (size);
}
