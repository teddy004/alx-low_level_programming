#include "lists.h"

/**
  * insert_dnodeint_at_index -  inserts a new node at a given position
  * @h: header of double linked list
  * @idx: index of the node, starting from 0
  * @n: is a given number
  * Return: a address of nth node
  */
dlistint_t *insert_dnodeint_at_index(dlistint_t **h, unsigned int idx, int n)
{
	dlistint_t *new, *headcopy = *h;
	unsigned int i;

	new = malloc(sizeof(dlistint_t));
	if (new == NULL)
		return (NULL);
	new->n = n;
	while (headcopy != NULL && headcopy->prev != NULL)
	{
		headcopy = headcopy->prev;
		*h = (*h)->prev;
	}
	if (idx == 0)
	{
		free(new);
		return (add_dnodeint(h, n));
	}

	for (i = 0; (i < idx - 1) && headcopy != NULL; i++)
		headcopy = headcopy->next;
	if (headcopy == NULL)
	{
		free(new);
		return (NULL);
	}
	if (headcopy->next == NULL)
	{
		new->next = NULL;
		new->prev = headcopy;
		headcopy->next = new;
	} else
	{
		new->next = headcopy->next;
		new->prev = headcopy;
		headcopy->next->prev = new;
		headcopy->next = new;
	}
	return (new);
}
