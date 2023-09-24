#include "sort.h"

/**
 * bubble_sort - function sorting array by bubble sort
 * @array: array to sorted
 * @size: array size
 */
void bubble_sort(int *array, size_t size)
{
	size_t i, j, optimize = size - 1;
	int swap = 0, temp;

	/* when list is empty or with only one element */
	if (size < 2)
		return;
	for (i = 0; i < size; i++)
	{
		/*
		 * optimize variable for saving time
		 * when largest object appears on far most right
		 */
		for (j = 0; j < optimize; j++)
		{
			if (array[j] > array[j + 1])
			{
				swap = 1;
				temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;
				print_array(array, size);
			}
		}
		/* if no swap occurs then list is sorted */
		if (swap == 0)
			return;
		swap = 0;
		optimize--;
	}
}
