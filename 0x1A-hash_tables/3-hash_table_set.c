#include "hash_tables.h"

/**
 * hash_table_add - adds an element to the @ht hash table when it doesn't exist
 *
 * @key: the key (cannot be empty)
 * @new_value: duplicated value associated with the key
 *
 * Return: the new node, NULL if fails
 */

hash_node_t *hash_table_add(const char *key, char *new_value)
{
	hash_node_t *new_node = NULL;

	new_node = malloc(sizeof(hash_node_t));
	if (!new_node)
	{
		free(new_value);
		return (NULL);
	}

	new_node->key = strdup(key);
	new_node->value = new_value;
	if (!new_node->key || !new_node->value)
	{
		if (new_node->key)
			free(new_node->key);
		free(new_value);
		return (NULL);
	}
	return (new_node);
}

/**
 * hash_table_set - adds or sets an element to the @ht hash table
 *
 * @ht: the hash table to add or update the key/value to
 * @key: the key (cannot be empty)
 * @value: value associated with the key
 *
 * Return: 1 if it succeeded, 0 otherwise
 */

int hash_table_set(hash_table_t *ht, const char *key, const char *value)
{
	unsigned long int index;
	hash_node_t *new_node = NULL, *tmp_node = NULL;
	char *new_value = NULL;

	if (!ht || !key || !value || strlen(key) == 0)
		return (0);

	index = key_index((const unsigned char *)key, ht->size);
	tmp_node = ht->array[index];

	new_value = strdup(value);
	if (!new_value)
		return (0);

	while (tmp_node)
	{
		if (strcmp(tmp_node->key, key) == 0)
		{
			free(tmp_node->value);
			tmp_node->value = new_value;
			break;
		}
		tmp_node = tmp_node->next;
	}

	if (!tmp_node)
	{
		new_node = hash_table_add(key, new_value);
		if (!new_node)
			return (0);
		new_node->next = ht->array[index];
		ht->array[index] = new_node;
	}

	return (1);
}
