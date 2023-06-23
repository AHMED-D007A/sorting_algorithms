#include "sort.h"

/**
 * swapi - swap two integers.
 * @n: the first integer.
 * @b:the second integer.
*/
void swapi(int *n, int *b)
{
	int temp;

	temp = *b;
	*b = *n;
	*n = temp;
}

/**
 * lomuto - do the quicksort by getting pivot in its place between
 * the left which contian lower value and the right in oppsite.
 * @array: the given array.
 * @low: the last index in the array or the group.
 * @high:the first index in the array or the group.
 * @size: the size of the array.
 * Return: the index of the pivot to divide arr to two groups.
*/
int lomuto(int *array, int low, int high, int size)
{
	int pivot_val = array[high];
	int i = low, j;

	for (j = low; j < high; j++)
	{
		if (array[j] <= pivot_val)
		{
			swapi(&array[i], &array[j]);
			print_array(array, size);
			i++;
		}
	}
	swapi(&array[i], &array[high]);
	print_array(array, size);

	return (i);
}

/**
 * quicksort_recursion - the recursive function that will be used to order.
 * @array: the given array.
 * @low: the last index in the array or the group.
 * @high:the first index in the array or the group.
 * @size: the size of the array.
*/
void quicksort_recursion(int *array, int low, int high, int size)
{
	int pivot_indx;

	if (low < high)
	{
		pivot_indx = lomuto(array, low, high, size);
		if (low < pivot_indx - 1)
			quicksort_recursion(array, low, pivot_indx - 1, size);
		if (high > pivot_indx + 1)
			quicksort_recursion(array, pivot_indx + 1, high, size);
	}
}

/**
 * quick_sort -function that impelement the quick sort algorithm.
 * @array: the given array to be sorted.
 * @size: the given size of the array.
*/
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;
	quicksort_recursion(array, 0, (int)size - 1, (int)size);
}
