#include "main.h"

/**
 * infinite_add - Adds two numbers
 * @n1: The first number
 * @n2: The second number
 * @r: The buffer for storing the result
 * @size_r: The size of the buffer
 *
 * Return: If result can be stored in r, then r, otherwise 0
 */
char *infinite_add(char *n1, char *n2, char *r, int size_r)
{
	int n1_len, n2_len, max_len, i;
	char n1_dig, n2_dig, carry, rem, tmp;

	for (n1_len = 0; *(n1 + n1_len) != '\0'; n1_len++)
		carry = 0;
	for (n2_len = 0; *(n2 + n2_len) != '\0'; n2_len++)
		rem = 0;
	max_len = n1_len > n2_len ? n1_len : n2_len;
	i = max_len;
	if (size_r < max_len + 1)
		return (0);
	*(r + max_len) = '\0';
	i--;
	n1_len--;
	n2_len--;
	for (; i >= 0; i--)
	{
		n1_dig = n1_len >= 0 ? *(n1 + n1_len) - '0' : 0;
		n2_dig = n2_len >= 0 ? *(n2 + n2_len) - '0' : 0;
		rem = (n1_dig + n2_dig + carry) % 10;
		carry = (n1_dig + n2_dig + carry) / 10;
		*(r + i) = (rem + '0');
		n1_len--;
		n2_len--;
	}
	if (carry > 0 && size_r >= max_len + 2)
	{
		for (i = max_len + 1; i > 0; i--)
		{
			tmp = *(r + i);
			*(r + i) = *(r + i - 1);
			*(r + i - 1) = tmp;
		}
		*(r + i) = carry + '0';
		return (r);
	}
	return ((carry > 0 && size_r < max_len + 2) ? 0 : r);
}
