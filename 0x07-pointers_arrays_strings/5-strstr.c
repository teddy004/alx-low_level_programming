#include "main.h"
/**
* _strstr - this function locates a substring
* @haystack:character string
* @needle:character string
* Return: a pointer to the beginning of substring or NULL
**/
char *_strstr(char *haystack, char *needle)
{
	int i;
	int j;
	int l;

	for (i = 0; haystack[i] != '\0'; i++)
	{
		for (l = i, j = 0; needle[j] != '\0'; j++, l++)
		{
			if (needle[j] != haystack[l] || haystack[l] == '\0')
			{
				break;
			}
		}
		if (needle[j] == '\0')
		{
			return (haystack + i);
		}
	}
	return (0);
}
