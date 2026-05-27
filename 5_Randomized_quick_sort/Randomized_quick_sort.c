#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void swap(int *a, int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

int partition(int arr[], int low, int high)
{
    int pivot = arr[high];
    int i = low - 1;

    for(int j = low; j < high; j++)
    {
        if(arr[j] < pivot)
        {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }

    swap(&arr[i + 1], &arr[high]);

    return i + 1;
}

int randomizedPartition(int arr[], int low, int high)
{
    int random = low + rand() % (high - low + 1);

    swap(&arr[random], &arr[high]);

    return partition(arr, low, high);
}

void randomizedQuickSort(int arr[], int low, int high)
{
    if(low < high)
    {
        int pi = randomizedPartition(arr, low, high);

        randomizedQuickSort(arr, low, pi - 1);
        randomizedQuickSort(arr, pi + 1, high);
    }
}

void printArray(int arr[], int n)
{
    for(int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
}

int main()
{
    int arr[] = {8, 3, 1, 7, 0, 10, 2};
    int n = sizeof(arr) / sizeof(arr[0]);

    srand(time(0));

    printf("Original Array:\n");
    printArray(arr, n);

    randomizedQuickSort(arr, 0, n - 1);

    printf("\nSorted Array:\n");
    printArray(arr, n);

    return 0;
}