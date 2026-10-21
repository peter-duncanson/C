// Sorts an array of integers using Quicksort algorithm

#include <stdio.h>

#define N 10

void quicksort(int a[], int low, int high);
int split(int a[], int low, int high);

int main(void)
{

    return 0;
}

void quicksort(int a[], int low, int high)
{
    int middle;

    if (low >= high) return;

    middle = split(a, low, high);
    quicksort(a, low, middle - 1);
    quicksort(a, middle + 1, high);
}

int split(int a[], int low, int high)
{
    int part_element = a[low];

    for (;;)
    {
        while (low < high && a[low] <= part_element)
        {
            low++;
        }
        if (low >= high) break;
        a[high--] = a[low];
    }

    a[high] = part_element;
    return high;
}
