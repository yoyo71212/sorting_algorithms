#include "sort.h"
#include <stdlib.h>

/**
 * get_max - Find the maximum value in an array
 *
 * @array: The array
 * @size: The number of elements in the array
 *
 * Return: The maximum value in the array
 */
int get_max(int *array, size_t size)
{
	int max;
	size_t i;

	max = array[0];
	for (i = 1; i < size; i++)
	{
		if (array[i] > max)
		{
			max = array[i];
		}
	}

	return (max);
}

/**
 * counting_sort - Function that sorts an array of integers in ascending order
 * using the Counting sort algorithm
 *
 * @array: The array
 * @size: The number of elements in the array
 *
 * Return: void
 */
void counting_sort(int *array, size_t size)
{
	int max, i;
	size_t j;
	int *counting_array;

	if (!array || !size)
	{
		return;
	}

	max = get_max(array, size);

	counting_array = (int *)malloc((max + 1) * sizeof(int));
	if (!counting_array)
	{
		return;
	}

	for (i = 0; i <= max; i++)
	{
		counting_array[i] = 0;
	}

	for (i = 0; ((size_t) i) < size; i++)
	{
		counting_array[array[i]]++;
	}

	print_array(counting_array, max + 1);

	j = 0;
	for (i = 0; i <= max; i++)
	{
		while (counting_array[i] > 0)
		{
			array[j++] = i;
			counting_array[i]--;
		}
	}

	free(counting_array);
	print_array(array, size);
}
