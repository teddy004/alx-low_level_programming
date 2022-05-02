#include <stdio.h>
#include "main.h"

/**
* clear_bit - a function that sets the value of a bit
*to 0 at a given index
* @n: a pointer that point to a number
* @index: is the index, starting from 0 of the bit
*you want to set
* Return: 1 if it worked, or -1 if an error occurred
**/

int clear_bit(unsigned long int *n, unsigned int index)
{
	if (index >= 64)
		return (-1);
	*n &= ~(1 << index);
	return (1);
}
