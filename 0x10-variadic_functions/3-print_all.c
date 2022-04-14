#include "variadic_functions.h"
#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>

/**
* print_char - prints a char
* @vargs: argument
* Return: void
*/
void print_char(va_list vargs)
{
printf("%c", va_arg(vargs, int));
}

/**
* print_integer - prints an integer
* @vargs: argument
* Return: void
*/
void print_integer(va_list vargs)
{
printf("%d", va_arg(vargs, int));
}

/**
* print_float - prints a float
* @vargs: argument
* Return: void
*/
void print_float(va_list vargs)
{
printf("%f", va_arg(vargs, double));
}

/**
* print_string - prints a string
* @vargs: argument
* Return: void
*/
void print_string(va_list vargs)
{
char *ch;
ch = va_arg(vargs, char *);
if (ch == NULL)
{
printf("(nil)");
return;
}
printf("%s", ch);
}

/**
* print_all - a function prints all arguments
* @format: the format
* Return: void
*/

void print_all(const char * const format, ...)
{
int i, j;
char *str = "";
va_list args;

form p[] = {
{"c", print_char},
{"i", print_integer},
{"f", print_float},
{"s", print_string},
{NULL, NULL},
};


va_start(args, format);

i = 0;
while (format && format[i])
{
j = 0;
while (p[j].f)
{
if (*(p[j].f) == format[i])
{
printf("%s", str);
p[j].func(args);
str = ", ";
}
j++;
}
i++;
}

va_end(args);
printf("\n");
}
