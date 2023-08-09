#include "main.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * str_concat - function that concatenates two strings.
 * @s1: first string to concatenate
 * @s2: second string to concatenate
 *
 * Return: two strings concatenated
 */

char *str_concat(char *s1, char *s2)
{
	char *ptstr;
	int count = 0, i = 0, j = 0, k = 0;

	if (s1 == NULL)
		s1 = "";
	if (s2 == NULL)
		s2 = "";
	while (s1[i])
		i++;
	while (s2[j])
		j++;

	count = i + j;
	ptstr = malloc((count * sizeof(char) + 1));

	if (ptstr == NULL)
		return (NULL);

	j = 0;

	while (k < count)
	{
		if (k <= i)
			ptstr[k] = s1[k];

		if (k >= i)
		{
			ptstr[k] = s2[j];
			j++;
		}
		k++;
	}

	ptstr[k] = '\0';
	return (ptstr);
}
