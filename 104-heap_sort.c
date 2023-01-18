#include "sort.h"

/**
 * heap_sort - sort array of ints in asc order using heap sort
 * @array: given array
 * @size: size of array
 *
 * Return: void
 */
void heap_sort(int *array, size_t size)
{
    int int_size = (int)size;
    int idx;

    for (idx = int_size / 2 - 1; idx > 0; idx--)
        heap_it_up(array, size, size, idx);

    for (idx = int_size - 1; idx >= 0; idx--)
    {
        swappy_boi(&array[0], &array[idx]);
        if (idx > 0)
            print_array(array, size);
        heap_it_up(array, idx, size, 0);
    }
}

/**
 * swappy_boi - swaps elements
 * @x: element 1
 * @y: element 2
 *
 * Return: void
 */
void swappy_boi(int *x, int *y)
{
    int tmp = *x;

    *x = *y;
    *y = tmp;
}

/**
 * heap_it_up - Building that heap
 * @array: given array
 * @size_array: size of sorted array
 * @size: size of array
 * @idx: index
 *
 * Return: void
 */
void heap_it_up(int *array, int size_array, size_t size, int idx)
{
    int rt = 2 * idx + 2;
    int lt = 2 * idx + 1;
    int big = idx;

    if (lt < size_array && array[lt] > array[big])
        big = lt;

    if (rt < size_array && array[rt] > array[big])
        big = rt;

    if (big != idx)
    {
        swappy_boi(&array[idx], &array[big]);
        print_array(array, size);
        heap_it_up(array, size_array, size, big);
    }
}
