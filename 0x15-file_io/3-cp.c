#include "main.h"
#include <stdio.h>
#include <stdlib.h>

#define BUFFER_SIZE 1024

/**
 * error_exit - Display an error message and exit the
 * program with a specified exit code.
 * @code: Exit code.
 * @message: Error message to display.
 */

void error_exit(int code, const char *message)
{
	dprintf(STDERR_FILENO, "%s\n", message);
	exit(code);
}

/**
 * main - Program that copies the content of a file to another file.
 * @argc: Number of arguments.
 * @argv: An array of pointers to the arguments.
 *
 * Return: 0 for success, or otherwise  an exit code on failure.
 */

int main(int argc, char *argv[])
{
	int m_src, m_dest;
	ssize_t r, w;
	char buf[BUFFER_SIZE];
	const char *file_from = argv[1];
	const char *file_to = argv[2];

	if (argc != 3)
	{
		error_exit(97, "Usage: cp file_from file_to");
	}
	m_src = open(file_from, O_RDONLY);
	if (m_src == -1)
	{
		error_exit(98, "Error: Can't read from file");
	}
	m_dest = open(file_to, O_WRONLY | O_CREAT | O_TRUNC, 0664);
	if (m_dest == -1)
	{
		error_exit(99, "Error: Can't write to file");
	}
	while ((r = read(m_src, buf, BUFFER_SIZE)) > 0)
	{
		w = write(m_dest, buf, r);
		if (w == -1)
		{
			error_exit(99, "Error: Can't write to file");
		}
	}
	if (r == -1)
	{
		error_exit(98, "Error: Can't read from file");
	}
	if (close(m_src) == -1 || close(m_dest) == -1)
	{
		error_exit(100, "Error: Can't close file descriptor");
	}
	return (0);
}
