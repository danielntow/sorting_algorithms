#include "sort.h"

/**
 * counting_sort - sorts an array of integers in ascending order
 * using the Counting sort algorithm
 * @array: the array to be sorted
 * @size: the size of the array
 */
void counting_sort(int *array, size_t size)
{
	int *count, *output;
	int max, i;

	if (array == NULL || size < 2)
		return;

	/* Find the maximum value in the array */
	max = array[0];
	for (i = 1; i < (int)size; i++)
	{
		if (array[i] > max)
			max = array[i];
	}

	/* Allocate memory for the count and output arrays */
	count = malloc(sizeof(int) * (max + 1));
	output = malloc(sizeof(int) * size);
	if (count == NULL || output == NULL)
	{
		free(count);
		free(output);
		return;
	}

	/* Initialize the count array to zero */
	for (i = 0; i <= max; i++)
		count[i] = 0;

	/* Count the frequency of each element in the array */
	for (i = 0; i < (int)size; i++)
		count[array[i]]++;

	/* Calculate the cumulative sum of the count array */
	for (i = 1; i <= max; i++)
		count[i] += count[i - 1];

	/* Print the count array */
	print_array(count, max + 1);

	/* Copy the elements from the array to the output array in sorted order */
	for (i = size - 1; i >= 0; i--)
	{
		output[count[array[i]] - 1] = array[i];
		count[array[i]]--;
	}

	/* Copy the output array back to the original array */
	for (i = 0; i < (int)size; i++)
		array[i] = output[i];

	/* Free the allocated memory */
	free(count);
	free(output);
}
