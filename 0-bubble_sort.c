#include "sort.h"

/**
 * bubble_sort - a function that implement bubble sort algorithms.
 * @array: the given pointer to the given array to be sorted.
 * @size: the size of the given array.
*/
void bubble_sort(int *array, size_t size)
{
	size_t i, j;
	int temporary, check;

	for (i = 0; i < size; i++)
	{
		check = 0;
		for (j = 0; j < size - 1; j++)
		{
			if (array[j] > array[j + 1])
			{
				temporary = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temporary;
				check = 1;
				print_array(array, size);
			}
		}
		if (check == 0)
			break;
	}
}
