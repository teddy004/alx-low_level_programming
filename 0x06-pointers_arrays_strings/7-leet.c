#include "main.h"

/**
* *leet - a function that encodes a string into 1337
* @str: string
* Return: string
**/

char *leet(char *str)
{
	int i, j;

	char s[] = "a4e3o0t7l1";

	i = 0;
	j = 0;

	while (str[i] != '\0')
	{
		for (j = 0; j < 10; j += 2)
		{
			if (str[i] == s[j] || str[i] == s[j] - 32)
			{
				str[i] = s[j + 1];
				break;
			}
		}
		i++;
	}
	return (str);
}
