#include "main.h"
/**
* _strpbrk - function searches string for any set of bytes
* @s: string
* @accept: string
* Return: a pointer to the byte in s
**/

char *_strpbrk(char *s, char *accept)
{
	int i;
	int j;

	for (i = 0; s[i] != '\0'; i++)
	{
		for (j = 0; accept[j] != '\0'; j++)
		{
			if (s[i] == accept[j])
				return (s + i);
		}
	}
	return (0);
}
