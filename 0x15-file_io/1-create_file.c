#include "main.h"

/**
* create_file - a function that creates a file
* @filename: the filename
* @text_content: a NULL terminated string to write to the file
* Return: 1 on success, -1 on failure
**/

int create_file(const char *filename, char *text_content)
{
	int f;
	int length, res;

	if (filename == NULL)
		return (-1);
	f = open(filename, O_WRONLY | O_CREAT | O_TRUNC, 0600);
	if (f == -1)
		return (-1);

	if (!text_content)
		return (1);
	length = 0;
	while (text_content[length] != '\0')
		length += 1;

	res = write(f, text_content, length);
	if (res != length)
		return (-1);
	res = close(f);
	if (res == -1)
		exit(-1);

	return (1);
}
