#include "sort.h"

/**
 * selection_sort - Sorts an array of integers in ascending order using
 * the Selection Sort algorithm.
 * @array: The array to be sorted
 * @size: Number of elements in the array
 */
void selection_sort(int *array, size_t size)
{
    size_t i, index;
    int tmp, swap, flag = 0;

    if (array == NULL || size < 2)
        return;

    for (i = 0; i < size; i++)
    {
        tmp = i;
        flag = 0;

        /* Find the index of the minimum element in the unsorted part */
        for (index = i + 1; index < size; index++)
        {
            if (array[tmp] > array[index])
            {
                tmp = index;
                flag += 1;
            }
        }

        /* Swap the found minimum element with the first element */
        swap = array[i];
        array[i] = array[tmp];
        array[tmp] = swap;

        /* Print the array after each swap if any swaps occurred */
        if (flag != 0)
            print_array(array, size);
    }
}

