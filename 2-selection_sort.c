#include "sort.h"

/**
 * selection_sort - function that impelement the selection sort algorithm.
 * @array: the given array to be sorted.
 * @size: the size of the given array.
*/
void selection_sort(int *array, size_t size)
{
	size_t i, j;
	int index, mini, check = 1;

	for (i = 0; i < size; i++)
	{
		check = 1;
		mini = array[i];
		for (j = 1 + i; j < size; j++)
		{
			if (array[j] < mini)
			{
				index = j;
				mini = array[j];
				check = 0;
			}
		}
		if (check == 0)
		{
		array[index] = array[i];
		array[i] = mini;
		print_array(array, size);
		}
	}
}
