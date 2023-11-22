#include "sort.h"

/**
* get_max - A utility function to get the maximum value in arr[]
* @arr: The array
* @size: The size of the array
* Return: The maximum value in the array
*/
int get_max(int *arr, int size)
{
int i, max = arr[0];

for (i = 1; i < size; i++)
	if (arr[i] > max)
		max = arr[i];
return (max);
}

/**
* radix_count_sort - A function to perform counting sort of arr[] based on
* the digit represented by exp.
* @arr: The array to be sorted
* @size: The size of the array
* @exp: The exponent (10^i)
* @output: The output array to store temporary values
*/
void radix_count_sort(int *arr, size_t size, int exp, int *output)
{
int i;
int count[10] = {0};

for (i = 0; i < (int)size; i++)
	count[(arr[i] / exp) % 10]++;

for (i = 1; i < 10; i++)
	count[i] += count[i - 1];

for (i = size - 1; i >= 0; i--)
{
	output[count[(arr[i] / exp) % 10] - 1] = arr[i];
	count[(arr[i] / exp) % 10]--;
}

for (i = 0; i < (int)size; i++)
	arr[i] = output[i];
}

/**
* radix_sort - The main function to perform Radix Sort
* @array: The array to be sorted
* @size: The size of the array
*/
void radix_sort(int *array, size_t size)
{
int exp, max = 0;
int *output = NULL;

if (array == NULL || size < 2)
	return;

max = get_max(array, size);
output = malloc(size * sizeof(int));
if (output == NULL)
	return;

for (exp = 1; max / exp > 0; exp *= 10)
{
	radix_count_sort(array, size, exp, output);
	print_array(array, size);
}

free(output);
}
