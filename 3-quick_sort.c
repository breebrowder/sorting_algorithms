#include "sort.h"

/**
 * partition_setter - sets the partition index
 * @array: the array to be sorted
 * @current: the current index in array
 * @end: the last index in array
 * @Return: Returns int partition index
 */

int partition_setter(int *array, size_t current, size_t end)
{
	size_t pivot, i, j, tmp;
	
	pivot = array[end];  
 
	i = (current - 1);

	for (j = current; j <= end - 1; j++)
	{
		if (array[j] < pivot)
		{
			i++;
			tmp = array[j];
			array[j] = array[i];
			array[i] = tmp;
		}
	}
	tmp = array[j];
	array[j] = array[i];
	array[i] = tmp;
	return (i + 1);
}

/**
 * my_sort - sorts the array recursively by position
 * @current: current index
 * @end: last index
 * Return: returns void
 */

void my_sort(int *array, size_t current, size_t end)
{
	size_t idx;

	if (current < end)
    {
        idx = partition(array, current, end);

        my_sort(array, current, idx - 1);
        my_sort(array, idx + 1, end);
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
	size_t current, end;

	current = 0;
	end = size - 1;

	my_sort(array, current, end);
	print_array(array, size);
}