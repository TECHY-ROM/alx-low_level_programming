#include "main.h"
#include <stdlib.h>

/**
 * string_nconcat - function that concatenates two strings.
 * @s1: first string
 * @s2: second string
 * @n: number of bytes from s2 to concatenate
 *
 * Return: Pointer to the newly concatenated string
 */

char *string_nconcat(char *s1, char *s2, unsigned int n)
{
	char *s;
	unsigned int a, len_s1, len_s2;

	len_s1 = 0;
	while (s1[len_s1])
		len_s1++;

	len_s2 = 0;
	while (s2[len_s2])
		len_s2++;

	if (n >= len_s2)
		n = len_s2;

	s = malloc(sizeof(char) * (len_s1 + n + 1));
		if (s == NULL)
			return (NULL);

	for (a = 0; a < len_s1; a++)
		s[a] = s1[a];

	for (a = 0; a < n; a++)
		s[len_s1 + a] = s2[a];

	s[len_s1 + n] = '\0';

	return (s);
}
