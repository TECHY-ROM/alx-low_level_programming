#include "main.h"
#include <stdio.h>
#include <stdlib.h>

void util(char **, char *);
void create_word(char **, char *, int, int, int);

/**
 * strtow - function that splits a string into words.
 * @str: the string
 * ptwords: words pointer to return
 * Return: a pointer to an array of strings (words)
 */

char **strtow(char *str)
{
	int i;
	int flag;
	int str_len;
	char **ptwords;

	if (str == NULL || str[0] == '\0' || (str[0] == ' ' && str[1] == '\0'))
		return (NULL);

	i = flag = str_len = 0;
	while (str[i])
	{
		if (flag == 0 && str[i] != ' ')
			flag = 1;
		if (i > 0 && str[i] == ' ' && str[i - 1] != ' ')
		{
			flag  = 0;
			str_len++;
		}
		i++;
	}

	str_len += flag == 1 ? 1 : 0;
	if (str_len == 0)
		return (NULL);
	ptwords = (char **)malloc(sizeof(char *) * (str_len + 1));
	if (ptwords == NULL)
		return (NULL);

	util(ptwords, str);
	ptwords[str_len] = NULL;
	return (ptwords);
}

/**
 * util - function for fetching words into an array
 * @ptwords: the string array
 * @str: the string
 */

void util(char **ptwords, char *str)
{
	int i;
	int j;
	int start;
	int flag;

	i = j = flag = 0;
	while (str[i])
	{
		if (flag == 0 && str[i] != ' ')
		{
			start = i;
			flag = 1;
		}
		if (i > 0 && str[i] == ' ' && str[i - 1] != ' ')
		{
			create_word(ptwords, str, start, i, j);
			j++;
			flag = 0;
		}
		i++;
	}

	if (flag == 1)
		create_word(ptwords, str, start, i, j);
}

/**
 * create_word - creates a word and insert it into the array
 * @ptwords: the array of strings
 * @str: the string
 * @start: the starting index of the word
 * @end: the stopping index of the word
 * @index: the index of the array to insert the word
 */

void create_word(char **ptwords, char *str, int start, int end, int index)
{
	int i;
	int j;

	i = end - start;
	ptwords[index] = (char *)malloc(sizeof(char) * (i - 1));

	for (j = 0; start < end; start++, j++)
		ptwords[index][j] = str[start];
	ptwords[index][j] = '\0';
}
