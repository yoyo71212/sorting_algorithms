#include "sort.h"
#include <stdlib.h>
/**
 * get_max - Find the maximum value in an array of integers
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
 * counting - Performs counting sort based on a significant digit
 *
 * @array: The array
 * @size: The number of elements in the array
 * @exp: The significant digit
 *
 * Return: void
 */
void counting(int *array, size_t size, int exp)
{
	int i;
	int *out;
	int count[10] = {0};

	out = (int *)malloc(sizeof(int) * size);
	if (!out)
	{
		return;
	}

	for (i = 0; ((size_t) i) < size; i++)
	{
		count[(array[i] / exp) % 10]++;
	}

	for (i = 1; i < 10; i++)
	{
		count[i] += count[i - 1];
	}

	for (i = size - 1; i >= 0; i--)
	{
		out[count[(array[i] / exp) % 10] - 1] = array[i];
		count[(array[i] / exp) % 10]--;
	}

	for (i = 0; ((size_t) i) < size; i++)
	{
		array[i] = out[i];
	}

	free(out);
}

/**
 * radix_sort - Function that sorts an array of integers in ascending order
 * using the Radix sort algorithm
 *
 * @array: The array
 * @size: The number of elements in the array
 *
 * Return: void
 */
void radix_sort(int *array, size_t size)
{
	int max, exp;

	if (!array || !size || size < 2)
	{
		return;
	}

	max  = get_max(array, size);
	for (exp = 1; max / exp > 0; exp *= 10)
	{
		counting(array, size, exp);

		print_array(array, size);
	}
}
