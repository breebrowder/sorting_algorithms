#include "sort.h"

/**
 * bubble_sort - sorts incoming array with bubble method
 * @array: incoming array
 * @size: size of incoming array
 * Return: returns void
 */

void bubble_sort(int *array, size_t size)
{
	size_t i, j, tmp;

	i = size;

	while (i > 0)
	{
		for (j = 0; j < (i - 1); j++)
		{
			if (array[j] > array[j + 1])
			{
				tmp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = tmp;
				print_array(array, size);
			}
		}
		i--;
	}
}
