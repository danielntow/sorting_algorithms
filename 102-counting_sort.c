#include "sort.h"

/**
 * counting_sort - Sorts an array of integers in ascending order using
 *                 the Counting Sort algorithm
 * @arr: Pointer to the array to be sorted
 * @size: Number of elements in the array
 */


void counting_sort(int *arr, size_t size)
{
	if (size <= 1)
		return;

	int max_val = arr[0];
	for (size_t i = 1; i < size; ++i)
	{
		if (arr[i] > max_val)
		{
			max_val = arr[i];
        	}
	}

	int counting_size = max_val + 1;
	int *count_arr = malloc(counting_size * sizeof(int));
	if (count_arr == NULL)
	{
		return;
	}

	for (int i = 0; i < counting_size; ++i)
	{
		count_arr[i] = 0;
	}

	for (size_t i = 0; i < size; ++i)
	{
		count_arr[arr[i]]++;
	}

	printf("Counting Array: ");
	for (int i = 0; i < counting_size; ++i)
	{
		printf("%d ", count_arr[i]);
	}
	printf("\n");

	size_t index = 0;
	for (int i = 0; i < counting_size; ++i)
	{
		while (count_arr[i] > 0)
		{
			arr[index++] = i;
			count_arr[i]--;
		}
	}

	free(count_arr);
}
