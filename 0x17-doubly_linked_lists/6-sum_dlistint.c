#include "lists.h"

/**
  * sum_dlistint - sum of all the data (n) of a dlistint_t linked list
  * @head: header of double linked list
  * Return: the sum of all nodes
  */
int sum_dlistint(dlistint_t *head)
{
	dlistint_t *headcopy;
	int sum = 0;

	headcopy = head;
	if (headcopy != NULL)
	{
		while (headcopy->prev != NULL)
			headcopy = headcopy->prev;

		while (headcopy != NULL)
		{
			sum += headcopy->n;
			headcopy = headcopy->next;
		}
		return (sum);
	}
	else
		return (0);
}
