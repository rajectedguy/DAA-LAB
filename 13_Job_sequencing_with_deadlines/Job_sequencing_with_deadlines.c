#include <stdio.h>

struct Job
{
    char id;
    int deadline;
    int profit;
};

void sort(struct Job jobs[], int n)
{
    for(int i = 0; i < n - 1; i++)
    {
        for(int j = i + 1; j < n; j++)
        {
            if(jobs[i].profit < jobs[j].profit)
            {
                struct Job temp = jobs[i];
                jobs[i] = jobs[j];
                jobs[j] = temp;
            }
        }
    }
}

int main()
{
    int n = 5;

    struct Job jobs[5] = {
        {'A', 2, 100},
        {'B', 1, 19},
        {'C', 2, 27},
        {'D', 1, 25},
        {'E', 3, 15}
    };

    sort(jobs, n);

    int slot[10] = {0};
    char result[10];

    int totalProfit = 0;

    for(int i = 0; i < n; i++)
    {
        for(int j = jobs[i].deadline - 1; j >= 0; j--)
        {
            if(slot[j] == 0)
            {
                slot[j] = 1;
                result[j] = jobs[i].id;
                totalProfit += jobs[i].profit;
                break;
            }
        }
    }

    printf("Selected Jobs: ");

    for(int i = 0; i < n; i++)
    {
        if(slot[i] == 1)
        {
            printf("%c ", result[i]);
        }
    }

    printf("\nTotal Profit = %d", totalProfit);

    return 0;
}