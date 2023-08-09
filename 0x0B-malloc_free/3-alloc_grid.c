#include "main.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * alloc_grid - function that frees a 2 dimensional
 * grid previously created by your alloc_grid function.
 * @width: define the row
 * @height: define the column
 *
 * Return: alloc_grid
 */

int **alloc_grid(int width, int height)
{
	int **pta;
	int i, j, k, l;

	if (width <= 0 || height <= 0)
		return (NULL);

	pta = malloc(sizeof(int *) * height);

	if (pta == NULL)
	{
		free(pta);
		return (NULL);
	}

	for (i = 0; i < height; i++)
	{
		pta[i] = malloc(sizeof(int) * width);

		if (pta[i] == NULL)
		{
			for (j = i; j >= 0; j--)
			{
				free(pta[j]);
			}

			free(pta);
			return (NULL);
		}
	}

	for (k = 0; k < height; k++)
	{
		for (l = 0; l < width; l++)
		{
			pta[k][l] = 0;
		}
	}

	return (pta);
}
