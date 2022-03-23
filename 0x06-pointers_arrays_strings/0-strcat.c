#include "main.h"

/**
* *_strcat - a function that concatenates two strings
* @dest: string
* @src: string
* Return: string
**/

char *_strcat(char *dest, char *src)
{
	int l;
	int i;

	for (l = 0; dest[l] != '\0'; l++)
	{
	}
	for (i = 0; src[i] != '\0'; i++)
	{
		dest[l + i] = src[i];
	}
	return (dest);
}
