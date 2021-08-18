#include "sort.h"

/**
 * selection_sort- function that sorts an array of integers in ascending order
 * @array: data to be sorted
 * @size: size of array
 *
 * Return: void
 */
void selection_sort(int *array, size_t size)
{
	size_t index; /* index of array */
	size_t tmp; /* temporary placeholder */
	size_t pos;
	int minimum, elementSwap;

	index = 0;
	elementSwap = 0;

	if (size < 2)
		return; /* cannot initiate swap with less than 2 */

	for (; index < size; index++) /* GO if index smaller than size of arr */
	{
		minimum = array[index];
		pos = index;

		for (tmp = index + 1; tmp < size; tmp++)
		{
			if (array[tmp] < minimum)
			{
				minimum = array[tmp];
				pos = tmp;
				elementSwap = 1;
			}
		}
		array[pos] = array[index];
		array[index] = minimum;
		if (elementSwap)
			print_array(array, size), elementSwap = 0;
	}
}
