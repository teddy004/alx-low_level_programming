#include <stdio.h>
#include <stdlib.h>
#include "main.h"

/**
* alloc_grid - a function that returns a pointer to 2 dimensional array of int
* @width: integer
* @height: integer
* Return: return a pointer to the array otherwise return NULL
**/

int **alloc_grid(int width, int height)
{
	int **p;

	int i;

	int j;

	if (width <= 0 || height <= 0)
		return (NULL);
	p = malloc(sizeof(int *) * height);
	if (p == NULL)
		return (NULL);
	for (i = 0; i < height; i++)
	{
		p[i] = malloc(sizeof(int) * width);
		if (p[i] == NULL)
		{
			for (i = i - 1; i >= 0; i--)
			{
				free(p[i]);
			}
			free(p);
			return (NULL);
		}
	}
	for (i = 0; j < width; j++)
		p[i][j] = 0;
	return (p);
}
