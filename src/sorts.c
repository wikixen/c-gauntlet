/**
 * A collection of all sorts implemented in C
 */
#include "../lib/sorts.h"
#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include <limits.h>

int main(int argc, char const *argv[])
{
    int arr[] = {50, 20, 40, 30, 15, 35, 21, 50, 20, 40, 30, 15, 35, 21, 50, 20, 40, 30, 15, 35, 21, 50, 20, 40, 30, 15, 35, 21, 50, 20, 40, 30, 15, 35, 21};
    int len = sizeof(arr) / sizeof(int);
    // print_arr(test, len);

    return 0;
}

void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

void print_arr(int *arr, int len)
{
    for (int i = 0; i < len; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void insertion_sort(int *arr, int len)
{
    for (int i = 0; i < len; i++)
    {
        int j = i;
        while (j > 0 && (arr[j - 1] > arr[j]))
        {
            swap(&arr[j - 1], &arr[j]);
            j--;
        }
    }
}

void bubble_sort(int *arr, int len)
{
    for (int i = 0; i < len - 1; i++)
    {
        int swapped = 0;
        for (int j = 1; j < len - i - 1; j++)
        {
            if (arr[j] < arr[j - 1])
            {
                swap(&arr[j], &arr[j - 1]);
                swapped = 1;
            }
        }
        if (swapped == 0)
        {
            break;
        }
    }
}

void comb_sort(int *arr, int len)
{
    int gap = len;
    double shrink = 4.0 / 3.0;
    int sorted = false;

    while (sorted == false)
    {
        gap /= shrink;

        if (gap <= 1)
        {
            gap = 1;
            sorted = true;
        }
        else if (gap == 9 || gap == 10)
        {
            gap = 11;
        }

        int i = 0;
        while (i + gap < len)
        {
            if (arr[i] > arr[i + gap])
            {
                swap(&arr[i], &arr[i + 1]);
                sorted = false;
            }
            i++;
        }
    }
}

void cocktail_sort(int *arr, int len)
{
    for (int i = 0; i < len - 1; i++)
    {
        int swapped = false;
        for (int j = 1; j < len - i - 1; j++)
        {
            if (arr[j] < arr[j - 1])
            {
                swap(&arr[j], &arr[j - 1]);
                swapped = 1;
            }
        }
        if (swapped == false)
        {
            break;
        }

        swapped = false;
        for (int j = len - 1; j > 0; j--)
        {
            if (arr[j] < arr[j - 1])
            {
                swap(&arr[j], &arr[j - 1]);
                swapped = true;
            }
        }
        if (swapped == false)
        {
            break;
        }
    }
}

void selection_sort(int *arr, int len)
{
    int index = 0;
    for (int i = 0; i < len; i++)
    {
        int min = arr[i];
        for (int j = i + 1; j < len; j++)
        {
            if (arr[j] < min)
            {
                min = arr[j];
                index = j;
            }
        }

        if (arr[index] != arr[i])
        {
            swap(&arr[index], &arr[i]);
        }
    }
}

void gnome_sort(int *arr, int len)
{
    int index = 1;
    while (index < len)
    {
        if (index == 0 || arr[index] >= arr[index - 1])
        {
            index++;
        }
        else
        {
            swap(&arr[index], &arr[index - 1]);
            index--;
        }
    }
}

// Strand sort not implemented yet
int *strand_sort(int *arr, int len)
{
    if (len == 1)
    {
        return arr;
    }

    int n = 0;
    for (int i = 0; i < len; i++)
    {
        if (arr[0] <= arr[i])
        {
            n++;
        }
    }
    
    int temp_arr[n], j = 0;
    for (int i = 0; i < len; i++)
    {
        if (arr[0] <= arr[i])
        {
            temp_arr[j] = arr[i];
            printf("%d ", temp_arr[j]);
            j++;
        }
    }

    return arr;
}

int shell_sort(int *arr, int len)
{
    return 0;
}
