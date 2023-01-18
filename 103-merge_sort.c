#include "sort.h"

/**
 * merge_sort - sorts array of ints in asc. order
 * @array: pointer to array of ints
 * @size: size of array
 *
 * Return: void
 */
void merge_sort(int *array, size_t size)
{
    int *tmp = malloc(sizeof(array[0]) * size);

    arr_cp(array, tmp, 0, size);
    split_it(tmp, array, 0, size);
    free(tmp);
}

/**
 * split_it - Splits array until it reaches size of 1
 * @tmp: temp array
 * @array: given array
 * @start: beginning index
 * @end: ending index
 *
 * Return: void
 */
void split_it(int *tmp, int *array, int start, int end)
{
    int half = (end + start) / 2;

    if (end - start <= 1)
        return;

    split_it(array, tmp, start, half);
    split_it(array, tmp, half, end);
    big_merger(tmp, array, start, half, end);
}

/**
 * arr_cp - Copies array
 * @array: given array
 * @start: beginning index
 * @end: ending index
 * @tmp: temp array
 *
 * Return: void
 */
void arr_cp(int *array, int *tmp, int start, int end)
{
    int idx;

    for (idx = start; idx < end; idx++)
    {
        tmp[idx] = array[idx];
    }
}

/**
 * array_print - Prints array between index
 * @array: printed array
 * @start: beginning index
 * @end: ending index
 *
 * Return: void
 */
void array_print(int *array, int start, int end)
{
    int idx;

    for (idx = start; idx < end; idx++)
    {
        printf("%d", array[idx]);
        if (idx < end - 1)
            printf(", ");
        else
            printf("\n");
    }
}

/**
 * big_merger - Merges all arrays after split and compare
 * @array: given array
 * @tmp: temp array
 * @start: beginning index
 * @half: midpoint index
 * @end: ending index
 *
 * Return: void
 */
void big_merger(int *array, int *tmp, int start, int half, int end)
{
    int idx = start;
    int jdx = half;
    int kdx = start;

    for (kdx = start; kdx < end; kdx++)
    {
        if (idx < half && (jdx >= end || array[idx] <= array[jdx]))
        {
            tmp[kdx] = array[idx];
            idx++;
        }
        else
        {
            tmp[kdx] = array[jdx];
            jdx++;
        }
    }

    printf("Merging...\n[left]: ");
    array_print(array, start, half);
    printf("[right]: ");
    array_print(array, half, end);
    printf("[Done]: ");
    array_print(tmp, start, end);
}
