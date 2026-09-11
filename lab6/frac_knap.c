#include <stdio.h>
struct Item
{
    int weight;
    int profit;
    float ratio;
};
void sort(struct Item items[], int n)
{
    struct Item temp;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (items[i].ratio < items[j].ratio)
            {
                temp = items[i];
                items[i] = items[j];
                items[j] = temp;
            }
        }
    }
}
int main()
{
    int n, capacity;
    float totalProfit = 0;

    printf("Enter number of items: ");
    scanf("%d", &n);

    struct Item items[n];

    printf("Enter weight and profit of each item:\n");

    for (int i = 0; i < n; i++)
    {
        scanf("%d %d", &items[i].weight, &items[i].profit);
        items[i].ratio = (float)items[i].profit / items[i].weight;
    }

    printf("Enter knapsack capacity: ");
    scanf("%d", &capacity);

    sort(items, n);

    for (int i = 0; i < n; i++)
    {
        if (capacity >= items[i].weight)
        {
            capacity -= items[i].weight;
            totalProfit += items[i].profit;
        }
        else
        {
            totalProfit += items[i].ratio * capacity;
            break;
        }
    }
    printf("Maximum profit = %.2f\n", totalProfit);
    return 0;

}
