#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
/**
* main - entry point
* @argc: size of argv
* @argv: array
* Return: 0
**/
int main(int argc, char *argv[])
{
	int i, j, add = 0;

	for (i = 1; i < argc; i++)
	{
		if (argv[i][0] == '-')
		{
			for (j = 1; argv[i][j] != '\0'; j++)
			{
				if (isdigit(argv[i][j]) == 0)
				{
					printf("Error\n");
					return (1);
				}
			}
		}
		else
		{
			for (j = 0; argv[i][j] != '\0'; j++)
			{
				if (isdigit(argv[i][j]) == 0)
				{
					printf("Error\n");
					return (1);
				}
			}
		}
		add += atoi(argv[i]);
	}
	printf("%d\n", add);
	return (0);
}
