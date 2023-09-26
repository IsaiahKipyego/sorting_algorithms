#include "sort.h"

/**
 * merge_array - compare and merge array into a sorted array
 * @copy: buffer mem to store a copy of array
 * @array: to sort
 * @left: most index
 * @right: most index
 * @mid: item index
 */
void merge_array(int *copy, int *array, size_t left, size_t mid, size_t right)
{
	size_t i = left, j = mid, k = left;

	printf("Merging...\n");
	printf("[left]: ");
	print_array(copy + left, mid - left);
	printf("[right]: ");
	print_array(copy + mid, right - mid);

	while (k < right)
	{
		if (i < mid && (j >= right || copy[i] <= copy[j]))
		{
			array[k] = copy[i];
			i++;
		}
		else
		{
			array[k] = copy[j];
			j++;
		}
		k++;
	}
	printf("[Done]: ");
	print_array(array + left, right - left);
}

/**
 * split - splits array into two and merged by sort array
 * @copy: buffer mem to store a copy of array
 * @array: to split and sort
 * @left: index of left most item
 * @right: the index of right most item
 */
void split(int *copy, int *array, size_t left, size_t right)
{
	size_t mid = 0;

	if (right - left < 2)
		return;

	mid = (left + right) / 2;
	split(copy, array, left, mid);
	split(copy, array, mid, right);
	merge_array(copy, array, left, mid, right);

	for (mid = left; mid < right; mid++)
		copy[mid] = array[mid];
}

/**
 * merge_sort - sorts a given array using merge sort algorithm
 * @array: to sort
 * @size: of array
 */
void merge_sort(int *array, size_t size)
{
	int *array_copy;
	size_t i = 0;

	if (array == NULL || size < 2)
		return;

	array_copy = malloc(sizeof(int) * size);
	if (array_copy == NULL)
		return;

	/* copy the array to the buffer */
	while (i < size)
	{
		array_copy[i] = array[i];
		i++;
	}

	split(array_copy, array, 0, size);

	free(array_copy);
}
