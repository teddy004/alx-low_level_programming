#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lists.h"

/**
* listint_len - a func that returns the number of elements in a *linked list
* @h: points to the head of list
* Return: the number of elements in a list
**/

size_t listint_len(const listint_t *h)
{
	size_t node_C;
	const listint_t *next_ptr;

	node_C = 0;
	next_ptr = h;

	while (next_ptr != NULL)
	{
		next_ptr = next_ptr->next;
		node_C += 1;
	}
	return (node_C);
}
