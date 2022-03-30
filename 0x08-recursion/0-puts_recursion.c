#include "main.h"

/**
* _puts_recursion - a function that prints a string
* @s: pointer to array of char
* Return: print string to output
**/

void _puts_recursion(char *s)
{
if (*s == '\0')
{
_putchar('\n');
return;
}
_putchar(*s);
s++;
_puts_recursion(s);
}
