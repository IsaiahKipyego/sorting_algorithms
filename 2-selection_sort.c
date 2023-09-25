#include "sort.h"

/**
 * selection_sort - selection sort algorithm for sorting an array
 * @array: array to sort
 * @size: size of array to sort
 */
void selection_sort(int *array, size_t size)
{
	int small_index, temp, flag = 0;
	size_t m, n;

	if (size < 2)
		return;

	for (m = 0; m < size - 1; m++)
	{
		small_index = i;
		for (n = m + 1; n < size; n++)
		{
			/* checking whether there is a smaller element */
			if (array[n] < array[small_index])
			{
				small_index = n;
				flag = 1;
			}
		}
		temp = array[m];
		array[m] = array[small_index];
		array[small_index] = temp;
		if (flag == 1)
			print_array(array, size);
		flag = 0;
	}
}
