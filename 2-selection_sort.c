#include "sort.h"
/**
 * selection_sort - Function that sorts an array of integers in ascending order
 * using the Selection sort algorithm
 *
 * @array: The array to be sorted
 * @size: The number of elements in the array
 *
 * Return: void
 */
void selection_sort(int *array, size_t size)
{
	size_t i, j;
	int min, temp;

	for (i = 0; i < size; i++)
	{
		min = i;

		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[min])
			{
				min = j;
			}
		}

		if (((size_t) min) != i)
		{
			temp = array[i];
			array[i] = array[min];
			array[min] = temp;
			print_array(array, size);
		}
	}
}
