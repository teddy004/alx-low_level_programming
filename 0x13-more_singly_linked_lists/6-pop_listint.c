#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lists.h"

/**
* pop_listint - a func that deletes the head node of a list
* @head: a pointer to a pointer that point to a list
* Return: the head node's data(n)
**/

int pop_listint(listint_t **head)
{
	int data_n;
	listint_t *free_node;

	if (head == NULL)
		return (0);
	if (*head == NULL)
		return (0);
	data_n = 0;
	free_node = *head;
	data_n = (*head)->n;
	*head = (*head)->next;
	free(free_node);
	return (data_n);
}
