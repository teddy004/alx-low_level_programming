#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "lists.h"

/**
* add_node_end - adds a node to the end of a linked_list
* @head: pointer to the head of a linked_list
* @str: string
* Return: pointer to head of node
**/

list_t *add_node_end(list_t **head, const char *str)
{
	unsigned int size;
	list_t *new_node;
	list_t *next_ptr;
	char *copy_str;

	new_node = malloc(sizeof(list_t));
	if (new_node == NULL)
		return (NULL);
	copy_str = strdup(str);
	size = 0;

	while (str[size] != '\0')
		size += 1;

	new_node->str = copy_str;
	new_node->len = size;
	new_node->next = NULL;

	if (*head == NULL)
	{
		*head = new_node;
		return (*head);
	}
	next_ptr = *head;

	while (next_ptr->next != NULL)
		next_ptr = next_ptr->next;

	next_ptr->next = new_node;
	return (*head);
}
