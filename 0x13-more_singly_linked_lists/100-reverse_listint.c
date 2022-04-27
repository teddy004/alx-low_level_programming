#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lists.h"

/**
* reverse_listint - a function that reverses a list
* @head: a pointer to pointer that point to head of list
* Return: a pointer to the first node of the reversed list
*/

listint_t *reverse_listint(listint_t **head)
{
	listint_t *previous_ptr;
	listint_t *cly_ptr;

	if (*head == NULL || (*head)->next == NULL)
		return (*head);
	previous_ptr = *head;
	cly_ptr = (*head)->next;

	while (cly_ptr != NULL)
	{
		(*head)->next = cly_ptr->next;
		cly_ptr->next = previous_ptr;
		previous_ptr = cly_ptr;
		cly_ptr = (*head)->next;
	}
	*head = previous_ptr;

	return (*head);
}
