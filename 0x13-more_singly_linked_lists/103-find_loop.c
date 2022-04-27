#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "lists.h"

/**
* find_listint_loop - a function that finds the
*loop in a linked list
* @head: pointer to a list
* Return: The address of the node where the loop starts,
*or NULL if there is no loop
*/

listint_t *find_listint_loop(listint_t *head)
{
	listint_t *f_ptr, *s_ptr;
	bool is_loop;

	if (head == NULL)
		return (NULL);
	f_ptr = head;
	s_ptr = head;
	is_loop = false;

	while (f_ptr && s_ptr && f_ptr->next)
	{
		f_ptr = f_ptr->next->next;
		s_ptr = s_ptr->next;

		if (s_ptr == f_ptr)
		{
			is_loop = true;
			break;
		}
	}
	if (is_loop)
	{
		f_ptr = head->next;
		s_ptr = head;
	}
	while (f_ptr && f_ptr < s_ptr && is_loop)
	{
		s_ptr = s_ptr->next;
		f_ptr = f_ptr->next;
	}
	return (f_ptr);
}
