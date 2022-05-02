#include "main.h"

/**
* read_textfile - a function that reads a text file
*and prints it to the POSIX standard output
* @filename: the file name
* @letters: the number of letters
* Return: the actual number of letters or 0 if fails
**/

ssize_t read_textfile(const char *filename, size_t letters)
{
	int f, length, i, res;
	char *buffer;

	if (filename == NULL)
		return (0);
	/* open */

	f = open(filename, O_RDONLY);

	if (f == -1)
		return (0);

	buffer = malloc(sizeof(char) * letters);
	if (!buffer)
		return (0);

	read(f, buffer, letters);
	buffer[letters] = '\0';

	for (i = 0; buffer[i] != '\0'; i += 1)
		length += 1;

	res = close(f);
	if (res != 0)
		exit(-1);
	res = write(STDOUT_FILENO, buffer, length);
	if (res != length)
		return (0);
	free(buffer);

	return (length);
}
