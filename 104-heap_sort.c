#include "sort.h"

#define parent(x) (((x) - 1) / 2)
#define left(x) (((x) * 2) + 1)

/**
 * siftdown - Implement the sift-down heap sort algorithm
 *
 * @array: The array
 * @start: The starting index
 * @end: The ending index
 * @size: The number of elements in the array
 *
 * Return: void
 */
void siftdown(int *array, size_t start, size_t end, size_t size)
{
	int temp2;
	size_t root, child, temp;

	root = start;
	while (left(root) <= end)
	{
		child = left(root);

		temp = root;
		if (array[temp] < array[child])
		{
			temp = child;
		}

		if (((child + 1) <= end) && (array[temp] < array[child + 1]))
		{
			temp = child + 1;
		}

		if (root == temp)
		{
			return;
		}

		temp2 = array[root];
		array[root] = array[temp];
		array[temp] = temp2;
		print_array(array, size);

		root = temp;
	}
}

/**
 * heapify - Converts an array into a binary heap
 *
 * @array: The array
 * @size: The number of elements in the array
 *
 * Return: void
 */
void heapify(int *array, size_t size)
{
	ssize_t start, end;

	end = size - 1;
	start = parent(end);

	while (start >= 0)
	{
		siftdown(array, start, end, size);
		start--;
	}
}

/**
 * heap_sort - Function that sorts an array of integers in ascending order
 * using the Heap sort algorithm
 *
 * @array: The array
 * @size: The number of elements in the array
 *
 * Return: void
 */
void heap_sort(int *array, size_t size)
{
	int temp;
	size_t end;

	if (!array || !size)
	{
		return;
	}

	end = size - 1;
	heapify(array, size);

	while (end > 0)
	{
		temp = array[end];
		array[end] = array[0];
		array[0] = temp;
		print_array((const int *) array, size);
		end--;
		siftdown(array, 0, end, size);
	}
}
