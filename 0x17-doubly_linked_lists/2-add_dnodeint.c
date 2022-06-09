#include "lists.h"

/**
  * add_dnodeint - add a node at the begining of a double linked list
  * @head: header of double linked list
  * @n: number to set in a new node
  * Return: address of a new element
  */
dlistint_t *add_dnodeint(dlistint_t **head, const int n)
{
	dlistint_t *new;

	if (head == NULL)
		return (NULL);

	new = malloc(sizeof(dlistint_t));
	if (new == NULL)
		return (NULL);

	new->n = n;

	if (*head == NULL)
	{
		new->next = NULL;
		new->prev = NULL;
		*head = new;
	}
	else
	{
		while ((*head)->prev != NULL)
			(*head) = (*head)->prev;
		(*head)->prev = new;
		new->next = *head;
		new->prev = NULL;
		*head = new;
	}
	return (*head);
}
