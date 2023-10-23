#include "sort.h"
/**
 * partition - Implement the Lomuto partition scheme
 *
 * @array: The array
 * @size: The number of elements in the array
 * @start: The starting index
 * @end: The ending index
 *
 * Return: Pivot index
 */
size_t partition(int *array, size_t size, ssize_t start, ssize_t end)
{
	int pivot, i, j, temp;

	pivot = array[end];
	j = start;
	for (i = start; i < end; i++)
	{
		if (array[i] < pivot)
		{
			if (array[i] != array[j])
			{
				temp = array[i];
				array[i] = array[j];
				array[j] = temp;
				print_array((const int *) array, size);
			}
			j++;
		}
	}

	if (array[j] != array[end])
	{
		temp = array[j];
		array[j] = array[end];
		array[end] = temp;
		print_array((const int *) array, size);
	}

	return (j);
}

/**
 * helper - Helper function to quick_sort
 *
 * @array: The array
 * @size: The number of elements in the array
 * @start: The starting index
 * @end: The ending index
 *
 * Return: void
 */
void helper(int *array, size_t size, ssize_t start, ssize_t end)
{
	size_t pivot;

	if (start < end)
	{
		pivot = partition(array, size, start, end);

		helper(array, size, start, pivot - 1);
		helper(array, size, pivot + 1, end);
	}
}

/**
 * quick_sort - Function that sorts an array of integers in ascending order
 * using the Quick sort algorithm
 *
 * @array: The array
 * @size: The number of elements in the array
 *
 * Return: void
 */
void quick_sort(int *array, size_t size)
{
	if (!array || !size)
	{
		return;
	}

	helper(array, size, 0, size - 1);
}
