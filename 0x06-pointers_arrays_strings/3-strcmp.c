#include "main.h"

/**
* _strcmp - a function that copies a string
* @s1: string
* @s2: string
* Return: string
**/

int _strcmp(char *s1, char *s2)
{

	for (; *s1 != '\0' && *s2 != '\0'; s1++, s2++)
	{
		if (*s1 != *s2)
		{
			return (*s1 - *s2);
		}
		else if (*s1 == '\0' || *s2 == '\0')
		{
			break;
		}
	}

	if (*s1 == *s2)
	{
		return (0);
	}
	else
	{
	return (*s1 - *s2);
	}
}
