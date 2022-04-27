#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lists.h"

/**
* get_nodeint_at_index - a func that returns the nth node of a
*linked list
* @head: a pointer that point to a list
* @index: holds the index to return
* Return: the nth node of a listint_t or NULL if the node
*does not exist
**/

listint_t *get_nodeint_at_index(listint_t *head, unsigned int index)
{
	unsigned int i;
	listint_t *next_ptr;

	next_ptr = head;
	for (i = 0; i < index; i += 1)
	{
		if (next_ptr == NULL)
			return (NULL);
		next_ptr = next_ptr->next;
	}
	return (next_ptr);
}
