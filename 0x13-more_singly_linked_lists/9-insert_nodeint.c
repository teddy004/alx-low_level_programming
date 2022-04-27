#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lists.h"

/**
* insert_nodeint_at_index - a function that inserts a new
*node at a given position
* @head: a pointer to a pointer to a struct
* @idx: is the index of the list where the new node
*should be added. Index starts at 0
* @n: the data for the new node
* Return: the address of the new node, or NULL if it failed
*/

listint_t *insert_nodeint_at_index(listint_t **head, unsigned int idx, int n)
{
	listint_t *next_ptr;
	listint_t *previous_ptr;
	listint_t *new_node;
	unsigned int i;

	if (head == NULL)
		return (NULL);
	next_ptr = *head;
	previous_ptr = NULL;
	for (i = 0; i < idx; i += 1)
	{
		if (next_ptr == NULL)
			return (NULL);
		previous_ptr = next_ptr;
		next_ptr = next_ptr->next;
	}

	new_node = malloc(sizeof(listint_t));
	if (!new_node)
		return (NULL);
	new_node->n = n;
	new_node->next = next_ptr;
	if (idx == 0)
		*head = new_node;
	else
		previous_ptr->next = new_node;

	return (new_node);
}
