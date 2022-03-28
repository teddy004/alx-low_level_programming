#include "main.h"
/**
* _strspn - a function that gets the length of a prefix substring
* @s: character
* @accept: character string
*
* Return: returns number of bytes in the initial segment s which consist
*of bytes from accept
**/
unsigned int _strspn(char *s, char *accept)
{
	int i;
	int j;
	int l = 0;

	for (i = 0; s[i] != '\0'; i++)
	{
		for (j = 0; accept[j] != '\0'; j++)
		{
			if (s[i] == accept[j])
			{
				l++;
				break;
			}
		}
		if (accept[j] == '\0')
			return (l);
	}
	return (l);
}
