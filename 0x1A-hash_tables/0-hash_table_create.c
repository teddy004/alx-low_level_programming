#include "hash_tables.h"

/**
 * hash_table_create - creates a hash table
 *
 * @size: the size of the array
 *
 * Return: the newly created hash_table, or NULL on failure
 */

hash_table_t *hash_table_create(unsigned long int size)
{
	hash_table_t *new_ht = NULL;
	unsigned long int index = 0;

	new_ht = malloc(sizeof(hash_table_t));
	if (new_ht)
	{
		new_ht->size = size;
		new_ht->array = malloc(sizeof(hash_node_t *) * size);
		if (!new_ht->array)
		{
			free(new_ht);
			return (NULL);
		}

		while (index < size)
		{
			new_ht->array[index] = NULL;
			index++;
		}
	}

	return (new_ht);
}
