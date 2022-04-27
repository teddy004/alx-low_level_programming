#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lists.h"

/**
* free_listint - a func that frees a list
* @head: a pointer point to the head of a list
*/

void free_listint(listint_t *head)
{
	listint_t *free_ptr;

	while (head != NULL)
	{
		free_ptr = head;
		head = head->next;
		free(free_ptr);
	}
}
