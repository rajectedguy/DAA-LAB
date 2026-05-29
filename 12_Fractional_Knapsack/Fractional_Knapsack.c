#include <stdio.h>

struct Item
{
    int profit;
    int weight;
    float ratio;
};

void sort(struct Item item[], int n)
{
    for(int i = 0; i < n - 1; i++)
    {
        for(int j = i + 1; j < n; j++)
        {
            if(item[i].ratio < item[j].ratio)
            {
                struct Item temp = item[i];
                item[i] = item[j];
                item[j] = temp;
            }
        }
    }
}

int main()
{
    int n = 3;

    struct Item item[3] = {
        {60, 10, 0},
        {100, 20, 0},
        {120, 30, 0}
    };

    int capacity = 50;

    for(int i = 0; i < n; i++)
    {
        item[i].ratio = (float)item[i].profit / item[i].weight;
    }

    sort(item, n);

    float totalProfit = 0;

    for(int i = 0; i < n; i++)
    {
        if(item[i].weight <= capacity)
        {
            totalProfit += item[i].profit;
            capacity -= item[i].weight;
        }
        else
        {
            totalProfit += item[i].ratio * capacity;
            break;
        }
    }

    printf("Maximum Profit = %.2f", totalProfit);

    return 0;
}