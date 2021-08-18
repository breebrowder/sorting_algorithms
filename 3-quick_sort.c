#include "sort.h"

/**
 * partition_setter - sets the partition index
 * @array: the array to be sorted
 * @size: size of incoming array
 * @current: the current index in array
 * @end: the last index in array
 * Return: Returns int partition index
 */

size_t partition_setter(int *array, size_t size, int current, int end)
{
	int pivot, tmp, i, j;
	(void)size;

	pivot = array[end];

	i = (current - 1);

	for (j = current; j < end; j++)
	{
		if (array[j] < pivot)
		{
			i++;
			if (i != j)
			{
				tmp = array[i];
				array[i] = array[j];
				array[j] = tmp;
				print_array(array, size);
			}
		}
	}
	if (i + 1 != end)
	{
		tmp = array[i + 1];
		array[i + 1] = array[end];
		array[end] = tmp;
		print_array(array, size);
	}
	return (i + 1);
}

/**
 * my_sort - sorts the array recursively by position
 * @array: array being sorted
 * @size: size of incoming array
 * @current: current index
 * @end: last index
 * Return: returns void
 */

void my_sort(int *array, size_t size, int current, int end)
{
	int idx;

	if (current < end)
	{
		idx = partition_setter(array, size, current, end);
		if (!(idx))
			my_sort(array, size, 0, end);
		else
		{
			my_sort(array, size, current, idx - 1);
			my_sort(array, size, idx + 1, end);
		}
	}
}

/**
 * quick_sort - uses lamuto partition scheme to sort an array
 * @array: incoming array for sort
 * @size: size of incoming array
 * Return: returns void
 */

void quick_sort(int *array, size_t size)
{
	my_sort(array, size, 0, size - 1);
}
