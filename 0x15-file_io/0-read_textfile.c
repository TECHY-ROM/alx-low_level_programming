#include "main.h"
#include <stdlib.h>

/**
 * read_textfile - function that reads a text file and
 * prints it to the POSIX standard output.
 * @filename: text file to be read
 * @letters: number of letters
 *
 * Return: actual number of letters read and printed,
 * 0 when function fails or filename is NULL.
 */

ssize_t read_textfile(const char *filename, size_t letters)
{
	int m;
	char *buf;
	ssize_t r, w;

	if (filename == NULL)
		return (0);

	m = open(filename, O_RDONLY);
	if (m == -1)
		return (0);

	buf = malloc(sizeof(char) * letters);
	if (buf == NULL)
	{
		close(m);
		return (0);
	}

	r = read(m, buf, letters);
	if (r == -1)
	{
		close(m);
		free(buf);
		return (0);
	}

	w = write(STDOUT_FILENO, buf, r);
	if (w == -1 || w != r)
	{
		close(m);
		free(buf);
		return (0);
	}

	close(m);
	free(buf);
	return (w);
}
