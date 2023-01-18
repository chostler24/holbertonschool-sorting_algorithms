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
    int idx = size / 2 - 1;
    int jdx = size - 1;

    for (; idx > 0; idx--)
        heap_it_up(array, size, idx);

    for (; jdx >= 0; jdx--)
    {
        swappy_boi(&array[0], &array[jdx]);
        heap_it_up(array, jdx, 0);
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
 * @size: size of array
 * @idx: index
 *
 * Return: void
 */
void heap_it_up(int *array, size_t size, int idx)
{
    int no = (int)(size);
    int rt = 2 * idx + 2;
    int lt = 2 * idx + 1;
    int big = idx;

    if (lt < no && array[lt] > array[big])
        big = lt;

    if (rt < no && array[rt] > array[big])
        big = rt;

    if (big != idx)
    {
        swappy_boi(&array[idx], &array[big]);
        heap_it_up(array, size, big);
    }
}
