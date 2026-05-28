#include <stdio.h>

int heap[100];
int size = 0;

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void insert(int value)
{
    int i = size;

    heap[size++] = value;

    while(i != 0 && heap[(i - 1) / 2] < heap[i])
    {
        swap(&heap[(i - 1) / 2], &heap[i]);

        i = (i - 1) / 2;
    }
}

void heapify(int i)
{
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if(left < size && heap[left] > heap[largest])
    {
        largest = left;
    }

    if(right < size && heap[right] > heap[largest])
    {
        largest = right;
    }

    if(largest != i)
    {
        swap(&heap[i], &heap[largest]);

        heapify(largest);
    }
}

void delete()
{
    if(size <= 0)
    {
        printf("Heap is empty\n");
        return;
    }

    printf("Deleted Element: %d\n", heap[0]);

    heap[0] = heap[size - 1];

    size--;

    heapify(0);
}

void display()
{
    for(int i = 0; i < size; i++)
    {
        printf("%d ", heap[i]);
    }

    printf("\n");
}

int main()
{
    insert(50);
    insert(30);
    insert(40);
    insert(10);
    insert(5);
    insert(20);

    printf("Priority Queue:\n");

    display();

    delete();

    printf("After Deletion:\n");

    display();

    return 0;
}