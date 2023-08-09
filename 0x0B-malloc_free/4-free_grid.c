#include "main.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * free_grid - function that frees a 2 dimensional
 * grid previously created by your alloc_grid function
 * @grid: the address of the two dimensional grid
 * @height: height of the grid
 *
 * Return: free grid
 */

void free_grid(int **grid, int height)
{
	int a;

	for (a = 0; a < height; a++)
	{
		free(grid[a]);
	}

	free(grid);
}
