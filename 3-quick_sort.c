#include "sort.h"

/**
* swap - Swaps two elements in an array
* @a: The first element to be swapped
* @b: The second element to be swapped
*/
void swap(int *a, int *b)
{
int temp;

temp = *a;
*a = *b;
*b = temp;
}

/**
* lomuto_partition - lomuto_partitions an array using the Lomuto scheme
* @array: The array to be lomuto_partitioned
* @size: The size of the array
* @low: The lowest index of the lomuto_partition
* @high: The highest index of the lomuto_partition
* Return: The final lomuto_partition index
*/
int lomuto_partition(int *array, size_t size, int low, int high)
{
int pivot, i, j;

pivot = array[high];
i = low - 1;
for (j = low; j < high; j++)
{
	if (array[j] <= pivot)
	{
		i++;
		if (i != j)
		{
			/* Swap the elements */
			swap(&array[i], &array[j]);
			/* Print the array after each swap */
			print_array(array, size);
		}
	}
}
if (array[i + 1] > pivot)
{
	/* Swap the pivot with the element at i + 1 */
	swap(&array[i + 1], &array[high]);
	/* Print the array after the swap */
	print_array(array, size);
}
return (i + 1);
}

/**
* quick_sort_helper - Recursively sorts an array
*                     using the Quick sort algorithm
* @array: The array to be sorted
* @size: The size of the array
* @low: The lowest index of the array
* @high: The highest index of the array
*/
void quick_sort_helper(int *array, size_t size, int low, int high)
{
int pi;

if (low < high)
{
	/* lomuto_partition the array */
	pi = lomuto_partition(array, size, low, high);
	/* Sort the left lomuto_partition */
	quick_sort_helper(array, size, low, pi - 1);
	/* Sort the right lomuto_partition */
	quick_sort_helper(array, size, pi + 1, high);
}
}

/**
* quick_sort - Sorts an array of integers in ascending order
* using the Quick sort algorithm
* @array: The array to be sorted
* @size: The size of the array
*/
void quick_sort(int *array, size_t size)
{
if (array == NULL || size < 2)
	return;

/* Call the helper function with low = 0 and high = size - 1 */
quick_sort_helper(array, size, 0, size - 1);
}

