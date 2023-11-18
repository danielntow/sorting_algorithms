#include "sort.h"

/**
 * shell_sort - sorts an array of integers in ascending order
 * using the Shell sort algorithm, using the Knuth sequence
 * @array: the array to be sorted
 * @size: the size of the array
 */
void shell_sort(int *array, size_t size)
{
    size_t gap, i, j;
    int temp;

    if (array == NULL || size < 2)
        return;

    /* Calculate the initial gap using the Knuth sequence */
    gap = 1;
    while (gap < size / 3)
        gap = gap * 3 + 1;

    /* Perform the Shell sort with decreasing gaps */
    while (gap > 0)
    {
        /* Compare elements that are gap apart and swap if needed */
        for (i = gap; i < size; i++)
        {
            temp = array[i];
            j = i;
            while (j >= gap && array[j - gap] > temp)
            {
                array[j] = array[j - gap];
                j -= gap;
            }
            array[j] = temp;
        }

        /* Print the array after each gap iteration */
        print_array(array, size);

        /* Decrease the gap by a factor of 3 */
        gap = (gap - 1) / 3;
    }
}
