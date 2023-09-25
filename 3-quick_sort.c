#include "sort.h"

/**
 * split - partitioning an a array using last element
 * @array: array to partition
 * @low: index of far left item of partition
 * @high: index of far most right item
 * @size: size of array
 *
 * Return: index of new pivot element
 */
int split(int *array, int low, int high, size_t size)
{
	int i = low - 1, temp, j;

	for (j = low; j <= high - 1; j++)
	{
		if (array[j] < array[high])
		{
			i++;
			if (i < j) /* swap */
			{
				temp = array[i];
				array[i] = array[j];
				array[j] = temp;
				print_array(array, size);
			}
		}
	}
	if (array[i + 1] > array[high]) /* move furthest right */
	{
		temp = array[i + 1];
		array[i + 1] = array[high];
		array[high] = temp;
		print_array(array, size);
	}

	return (i + 1);
}

/**
 * recursive_sort - recursively sorts array using quick sort algorithm
 * @array: array to sort
 * @low: index of far left item of partition
 * @high: index of far most right item
 * @size: size of array
 */
void recursive_sort(int *array, int low, int high, size_t size)
{
	int pivot;

	if (low < high)
	{
		pivot = split(array, low, high, size);
		recursive_sort(array, low, pivot - 1, size);
		recursive_sort(array, pivot + 1, high, size);
	}
}

/**
 * quick_sort - sorting an array using quick sort algorithm
 * @array: array to sort
 * @size: size of the array being sorted
 * Description: quick sort algorithm implemented using recursion
 */
void quick_sort(int *array, size_t size)
{
	recursive_sort(array, 0, size - 1, size);
}
