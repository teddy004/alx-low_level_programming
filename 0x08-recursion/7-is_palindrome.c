#include "main.h"

/**
* _strlen_recursion - return length of string
* @s: character string
* Return: string length
**/
int _strlen_recursion(char *s)
{
int i = 0;

if (*s == '\0')
return (0);
else
{
i = _strlen_recursion(s + 1);
i++;
}
return (i);
}

/**
* _scan - scan string
* @c: char
* @d: char
* Return: char
**/
int _scan(char *c, char *d)
{
if (*c != *d)
return (0);
else if (c >= d)
return (1);
else
return (_scan(c + 1, d - 1));
}

/**
* is_palindrome - checks if string is a palindrome
* @s: pointer to a string
* Return: 1 if palindrome and 0 if not
**/
int is_palindrome(char *s)
{
int i = _strlen_recursion(s);
char *c = s;
char *d = s + (i - 1);

if (i == 0)
return (1);
return (_scan(c, d));
}
