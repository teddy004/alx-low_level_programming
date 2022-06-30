#include "hash_tables.h"

/**
 * shash_table_create - creates a hash table
 *
 * @size: the size of the array
 *
 * Return: the newly created hash_table, or NULL on failure
 */

shash_table_t *shash_table_create(unsigned long int size)
{
	shash_table_t *new_sht = NULL;
	unsigned long int index = 0;

	new_sht = malloc(sizeof(shash_table_t));
	if (new_sht)
	{
		new_sht->size = size;
		new_sht->array = malloc(sizeof(shash_node_t *) * size);
		if (!new_sht->array)
		{
			free(new_sht);
			return (NULL);
		}

		while (index < size)
		{
			new_sht->array[index] = NULL;
			index++;
		}
		new_sht->shead = NULL;
		new_sht->stail = NULL;
	}

	return (new_sht);
}

/**
 * insert_node - handles the add, addend and insert of nodes in linked list
 *
 * @ht: the hash table to add the key/value to
 * @new_node: newly created node to insert
 */

void insert_node(shash_table_t *ht, shash_node_t *new_node)
{
	shash_node_t *tmp_node = NULL, *head = NULL;

	new_node->snext = NULL;
	new_node->sprev = NULL;
	if (!ht->shead && !ht->stail) /* if the linked list is empty */
	{
		ht->shead = new_node;
		ht->stail = new_node;
	}
	else if (strcmp(new_node->key, ht->shead->key) <= 0) /* if is <= first */
	{
		new_node->snext = ht->shead;
		new_node->snext->sprev = new_node;
		ht->shead = new_node;
	}
	else
	{
		head = ht->shead;
		while (head->snext && strcmp(new_node->key, head->snext->key) > 0)
			head = head->snext;
		new_node->snext = head->snext;
		new_node->sprev = head;
		tmp_node = head->snext;
		head->snext = new_node;
		if (!tmp_node)
			ht->stail = new_node;
		else
			tmp_node->sprev = new_node;
	}
}

/**
 * shash_table_add - adds element to the @ht hash table when it doesn't exist
 *
 * @ht: the hash table to add the key/value to
 * @key: the key (cannot be empty)
 * @value: duplicated value associated with the key
 *
 * Return: the new node, NULL if fails
 */

shash_node_t *shash_table_add(shash_table_t *ht, const char *key, char *value)
{
	shash_node_t *new_node = NULL;

	new_node = malloc(sizeof(shash_node_t));
	if (!new_node)
	{
		free(value);
		return (NULL);
	}

	new_node->key = strdup(key);
	new_node->value = value;
	if (!new_node->key || !new_node->value)
	{
		if (new_node->key)
			free(new_node->key);
		free(value);
		return (NULL);
	}

	insert_node(ht, new_node);
	return (new_node);
}

/**
 * shash_table_set - adds or sets an element to the @ht hash table
 *
 * @ht: the hash table to add or update the key/value to
 * @key: the key (cannot be empty)
 * @value: value associated with the key
 *
 * Return: 1 if it succeeded, 0 otherwise
 */

int shash_table_set(shash_table_t *ht, const char *key, const char *value)
{
	unsigned long int index;
	shash_node_t *new_node = NULL, *tmp_node = NULL;
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
		new_node = shash_table_add(ht, key, new_value);
		if (!new_node)
			return (0);
		new_node->next = ht->array[index];
		ht->array[index] = new_node;
	}

	return (1);
}

/**
 * shash_table_get - retrieves a value associated with a key
 *
 * @ht: the hash table to look into
 * @key: the key to looking for
 *
 * Return: the value associated with the element, or NULL if key not found
 */

char *shash_table_get(const shash_table_t *ht, const char *key)
{
	unsigned long int index;
	shash_node_t *tmp_node = NULL;

	if (!ht || !key || strlen(key) == 0)
		return (NULL);

	index = key_index((const unsigned char *)key, ht->size);
	tmp_node = ht->array[index];

	while (tmp_node)
	{
		if (strcmp(tmp_node->key, key) == 0)
			return (tmp_node->value);
		tmp_node = tmp_node->next;
	}

	return (NULL);
}

/**
 * shash_table_print - prints a hash table
 *
 * @ht: the hash table to print
 */

void shash_table_print(const shash_table_t *ht)
{
	shash_node_t *tmp_node = NULL;
	char *comma = "";

	if (ht)
	{
		printf("{");
		tmp_node = ht->shead;

		while (tmp_node)
		{
			printf("%s", comma);
			comma = ", ";

			if (tmp_node->key)
				printf("'%s': '%s'", tmp_node->key, tmp_node->value);

			tmp_node = tmp_node->snext;
		}
		printf("}\n");
	}
}

/**
 * shash_table_print_rev - rev prints a hash table
 *
 * @ht: the hash table to print
 */

void shash_table_print_rev(const shash_table_t *ht)
{
	shash_node_t *tmp_node = NULL;
	char *comma = "";

	if (ht)
	{
		printf("{");
		tmp_node = ht->stail;

		while (tmp_node)
		{
			printf("%s", comma);
			comma = ", ";

			if (tmp_node->key)
				printf("'%s': '%s'", tmp_node->key, tmp_node->value);

			tmp_node = tmp_node->sprev;
		}
		printf("}\n");
	}
}

/**
 * shash_table_delete - deletes a hash table
 *
 * @ht: the hash table to delete
 */

void shash_table_delete(shash_table_t *ht)
{
	shash_node_t *tmp_node = NULL;
	unsigned long int index = 0;

	if (ht)
	{
		while (index < ht->size)
		{
			while (ht->array[index])
			{
				tmp_node = ht->array[index];
				ht->array[index] = ht->array[index]->next;

				if (tmp_node->value)
					free(tmp_node->value);
				if (tmp_node->key)
					free(tmp_node->key);
				free(tmp_node);
			}
			free(ht->array[index]);
			index++;
		}
		free(ht->array);
		free((void *)ht);
	}
}
