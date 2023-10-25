#include "sort.h"
#include <stdio.h>
#include <stdlib.h>
/**
 * combine - Merge two subarrays into one sorted array
 *
 * @array: The array
 * @start: The starting index
 * @end: The ending index
 * @new_arr: The resultant array
 *
 * Return: void
 */
void combine(int *array, size_t start, size_t end,int *new_arr)
{
	size_t i, j, k, mid;

	i = start;
	j = (start + end) / 2;
	mid = j;

	printf("Merging...\n");

	printf("[left]: ");
	print_array(array + start, mid - start);

	printf("[right]: ");
	print_array(array + mid, end - mid);

	for (k = start; k < end; k++)
	{
		if (i < mid && (array[i] <= array[j] || j >= end))
		{
			new_arr[k] = array[i];
			i++;
		}
		else
		{
			new_arr[k] = array[j];
			j++;
		}
	}

	printf("[Done]: ");
	print_array(new_arr + start, end - start);
}

/**
 * helper - Implement the top-down merge sort algorithm
 *
 * @array: The array
 * @start: The starting index
 * @end: The ending index
 * @new_arr: The resultant array
 *
 * Return: void
 */
void helper(int *array, size_t start, size_t end, int *new_arr)
{
	size_t mid;

	if (end - start < 2)
	{
		return;
	}

	mid = (start + end) / 2;
	helper(new_arr, start, mid, array);
	helper(new_arr, mid, end, array);
	combine(array, start, end, new_arr);
}

/**
 * merge_sort - Function that sorts an array of integers in ascending order
 * using the Merge sort algorithm
 *
 * @array: The array
 * @size: The number of elements in the array
 *
 * Return: void
 */
void merge_sort(int *array, size_t size)
{
	int *new_array;
	size_t i;

	if (!array || size < 2)
	{
		return;
	}

	new_array = malloc(sizeof(int) * size);
	if (!new_array)
	{
		return;
	}

	for (i = 0; i < size; i++)
	{
		new_array[i] = array[i];
	}

	helper(new_array, 0, size - 1, array);

	free(new_array);
}
