#include "sort.h"

void swap(int *x, int *y);
void quick_sort_recursion(int *array, int low, int high);
int partition(int *array, int low, int high);

/**
 * swap - Swap two integers.
 * @x: Pointer to the first integer.
 * @y: Pointer to the second integer.
 */
void swap(int *x, int *y)
{
	int temp = *x;
	*x = *y;
	*y = temp;
}

/**
 * partition - Partition the array for quicksort.
 * @array: Array to be partitioned.
 * @low: Starting index.
 * @high: Ending index.
 *
 * Return: Index of the pivot element.
 */
int partition(int *array, int low, int high)
{
	int pivot = array[high];
	int i = low - 1;
	int j = low;

	for (; j < high; j++)
	{
		if (array[j] <= pivot)
		{
			i++;
			swap(&array[i], &array[j]);
		}
	}

	swap(&array[i + 1], &array[high]);
	return (i + 1);
}

/**
 * quick_sort_recursion - Recursively sort the array using quicksort.
 * @array: Array to be sorted.
 * @low: Starting index.
 * @high: Ending index.
 */
void quick_sort_recursion(int *array, int low, int high)
{
	if (low < high)
	{
		int pivot_index = partition(array, low, high);

		quick_sort_recursion(array, low, pivot_index - 1);
		quick_sort_recursion(array, pivot_index + 1, high);
	}
}

/**
 * quick_sort - Sort an array using quicksort algorithm.
 * @array: Array to be sorted.
 * @size: Size of the array.
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size <= 1)
		return;

	quick_sort_recursion(array, 0, (int)size - 1);
}
