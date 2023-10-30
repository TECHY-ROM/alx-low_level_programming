#include "main.h"
#include <string.h>

/**
 * append_text_to_file - function that appends text at the end of a file.
 * @filename: a pointer to the name of the file.
 * @text_content: Added content
 *
 * Return: If the function fails or filename is NULL -1 or if otherwise - 1.
 */

int append_text_to_file(const char *filename, char *text_content)
{
	int m;
	int rw;
	int txt_len = 0;

	if (!filename)
		return (-1);

	m = open(filename, O_WRONLY | O_APPEND);

	if (m == -1)
		return (-1);

	if (text_content)
	{
		for (txt_len = 0; text_content[txt_len]; txt_len++)
			;

		rw = write(m, text_content, txt_len);

		if (rw == -1)
			return (-1);
	}

	close(m);

	return (1);
}
