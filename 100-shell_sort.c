#include "sort.h"

/**
 * shell_sort - runs the shell sort algorithm
 * @array: array to sort
 * @size: size of array to sort
 */
void shell_sort(int *array, size_t size)
{
	int gap = 1;
	int i, j, temp;

	/* implementing the Knuth sequence */
	while (gap < (int)size)
		gap = (3 * gap) + 1;

	/*Knuth sequence to sort a list*/
	for (gap = (gap - 1) / 3; gap > 0; gap = (gap - 1) / 3)
	{
		for (i = gap; i < (int)size; i++)
		{
			temp = array[i];

			for (j = i; j >= gap && array[j - gap] > temp; j -= gap)
				array[j] = array[j - gap];

			array[j] = temp;
		}
		print_array(array, size);
	}
}
