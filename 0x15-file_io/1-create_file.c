#include "main.h"
#include <stdlib.h>
#include <string.h>

/**
 * create_file - function that creates a file.
 * @filename: a pointer to the name of the file to create
 * @text_content: pointer to a string to write to the file
 *
 * Return: --1 if the function fails or -1 if otherwise.
 */

int create_file(const char *filename, char *text_content)
{
	int m;
	size_t len;
	ssize_t result;

	if (filename == NULL)
	{
		return (-1);
	}

	m = open(filename, O_WRONLY | O_CREAT | O_TRUNC, 0600);
	if (m == -1)
	{
		return (-1);
	}

	if (text_content != NULL)
	{
		len = strlen(text_content);
		result = write(m, text_content, len);

		if (result == -1)
		{
			close(m);
			return (-1);
		}
	}

	close(m);
	return (1);
}
