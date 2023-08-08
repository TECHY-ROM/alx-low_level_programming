#include "main.h"
#include <stdlib.h>

/**
 * _strdup - A function that duplicate a string
 * @str: the string to duplicate
 *
 * Return: the string duplicated
 */

char *_strdup(char *str)

{
	char *ptstr;
	int str_len = 1;
	int count = 0;

	if (str == NULL)
		return (NULL);

	while (str[str_len])
	{
		str_len++;
	}

	ptstr = malloc((str_len * sizeof(char) + 1));

	if (ptstr == NULL)
		return (NULL);
	while (count < str_len)
	{
		ptstr[count] = str[count];
		count++;
	}

	ptstr[count] = '\0';
	return (ptstr);
}
