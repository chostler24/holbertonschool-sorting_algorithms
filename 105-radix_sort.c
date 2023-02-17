#include "sort.h"

/**
 * radix_sort - function sorts array of integers in asc order with radix sort
 * @array: given array
 * @size: size array
 *
 * Return: none
 */

void radix_sort(int *array, size_t size)
{
        int *res = NULL;
        int x = 1;
        int pos = 1;
        int max = 1;

        if (array == NULL || size < 2)
                return;

        res = malloc(sizeof(int) * size);

        if (res == NULL)
                return;

        max = array[0];

        for (; x < (int) size; x++)
                if (array[x] > max)
                        max = array[x];

        while (max / pos > 0)
        {
                sort_it(array, size, pos, res);
                print_array(array, size);
                pos = pos * 10;
        }

        free(res);
}

/**
 * sort_it - sorts array of ints in asc order using count sort
 * @array: given array
 * @size: size of array
 * @res: resulting array
 * @pos: position of int
 *
 * Return: none
 */

void sort_it(int *array, size_t size, int pos, int *res)
{
        int x = {0};
        int idx[10] = {0};

        for (x = 0; x < (int) size; x++)
                idx[(array[x] / pos) % 10]++;

        for (x = 1; x < 10; x++)
                idx[x] += idx[x - 1];

        for (x = (int) size - 1; x >= 0; x--)
        {
                res[idx[(array[x] / pos) % 10] - 1] = array[x];
                idx[(array[x] / pos) % 10]--;
        }

        for (x = 0; x < (int) size; x++)
                array[x] = res[x];
}
