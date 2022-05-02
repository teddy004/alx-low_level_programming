#include <stdio.h>
#include "main.h"

/**
* get_bit - a function that returns the value of a bit
*at a given index
* @n: long integer
* @index: is the index, starting from 0 of the bit
*you want to get
* Return: the value of the bit at index or -1 if an
*error occured
*/

int get_bit(unsigned long int n, unsigned int index)
{
	if (index >= 64)
		return (-1);
	return ((n & (1 << index)) ? 1 : 0);
}
