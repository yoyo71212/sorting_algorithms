#include "sort.h"
/**
 * get_gap - Calculates the initial gap for shell sort
 *
 * @size: The number of elements in the array
 *
 * Return: The initial gap value
 */
size_t get_gap(size_t size)
{
	size_t res;

	res = 1;
	while (res < size / 3)
	{
		res = (res * 3) + 1;
	}

	return (res);
}

/**
 * shell_sort - Function that sorts an array of integers in ascending order
 * using the Shell sort algorithm, using the Knuth sequence
 *
 * @array: The array
 * @size: The number of elements in the array
 *
 * Return: void
 */
void shell_sort(int *array, size_t size)
{
	size_t j, k, gap;
	int temp;

	if (!array || !size || size < 2)
	{
		return;
	}

	gap = get_gap(size);
	while (gap >= 1)
	{
		for (j = gap; j < size; j++)
		{
			temp = array[j];

			for (k = j; (k > gap - 1) && (array[k - gap] > temp); k -= gap)
			{
				array[k] = array[k - gap];
			}

			array[k] = temp;
		}

		print_array(array, size);

		gap = (gap - 1) / 3;
	}
}
