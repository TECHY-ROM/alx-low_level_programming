#include "main.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * argstostr - function that concatenates all the arguments of your program.
 * @ac: arguments count
 * @av: arguments array
 *
 * Return: a pointer tonew string or NULL if otherwise
 */

char *argstostr(int ac, char **av)
{
	char *ptstr, *s;
	int i;
	int j;
	int k;
	int str_len = 0;

	if (ac == 0 || av == NULL)
		return (NULL);

	for (i = 0; i < ac; i++)
	{
		s = av[i];
		j = 0;

		while (s[j++])
			str_len++;
		str_len++;
	}

	ptstr = (char *)malloc(sizeof(char) * (str_len + 1));
	if (ptstr == NULL)
		return (NULL);

	for (i = 0, j = 0; i < ac && j < str_len; i++)
	{
		s = av[i];
		k = 0;

		while (s[k])
		{
			ptstr[j] = s[k];
				k++;
				j++;
		}
		ptstr[j++] = '\n';
	}
	ptstr[j] = '\0';

	return (ptstr);
}
