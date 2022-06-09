#include "lists.h"

/**
* dlistint_len - get the length of nodes in a double linked list
* @h: header of double linked list
* Return: number of nodes
*/
size_t dlistint_len(const dlistint_t *h)
{
	size_t i = 0;
	int iniprint = 0;

	for (i = 0; h != NULL; i++)
	{
		if (h->prev != NULL && iniprint == 0)
		{
			h = h->prev;
			continue;
		}
		else if (h->prev == NULL)
		{
			iniprint = 1;
			i = 0;
		}
		h = h->next;
	}
	return (i);
}
