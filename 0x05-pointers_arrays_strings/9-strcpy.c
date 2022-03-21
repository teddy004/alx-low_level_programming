#include "main.h"
#include <stdio.h>
/**
 * _strcpy - entry point
 * Description: copies the string pointer, null byte, dest pointer
 * @dest: destiny
 * @src: font
 * Return: dest pointer
 */

char *_strcpy(char *dest, char *src)
{
	int i = 0, j = 0;

	for (; src[i] != '\0'; i++)
	{
		dest[i] = src[i];
	}
	dest[i] = '\0';
		j++;
	return (dest);
}
