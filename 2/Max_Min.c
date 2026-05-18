#include <stdio.h>

void maxMin(int arr[], int low, int high, int *max, int *min)
{
    int mid;
    int max1, min1, max2, min2;

    if (low == high)
    {
        *max = *min = arr[low];
        return;
    }

    if (high == low + 1)
    {
        if (arr[low] > arr[high])
        {
            *max = arr[low];
            *min = arr[high];
        }
        else
        {
            *max = arr[high];
            *min = arr[low];
        }
        return;
    }

    mid = (low + high) / 2;

    maxMin(arr, low, mid, &max1, &min1);

    maxMin(arr, mid + 1, high, &max2, &min2);

    if (max1 > max2)
        *max = max1;
    else
        *max = max2;

    if (min1 < min2)
        *min = min1;
    else
        *min = min2;
}

int main()
{
    int n, i;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter elements:\n");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    int max, min;

    maxMin(arr, 0, n - 1, &max, &min);

    printf("Maximum element = %d\n", max);
    printf("Minimum element = %d\n", min);

    return 0;
}