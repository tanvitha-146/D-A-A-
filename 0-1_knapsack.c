
#include <stdio.h>

int max(int a, int b) {
    return (a > b) ? a : b;
}

int main() {
    int n, capacity, i, w;

    printf("Enter number of items: ");
    scanf("%d", &n);

    int weight[n + 1], profit[n + 1];

    printf("Enter weights of items:\n");
    for (i = 1; i <= n; i++)
        scanf("%d", &weight[i]);

    printf("Enter profits of items:\n");
    for (i = 1; i <= n; i++)
        scanf("%d", &profit[i]);

    printf("Enter knapsack capacity: ");
    scanf("%d", &capacity);

    int V[n + 1][capacity + 1];

    for (i = 0; i <= n; i++) {
        for (w = 0; w <= capacity; w++) {
            if (i == 0 || w == 0)
                V[i][w] = 0;
            else if (weight[i] <= w)
                V[i][w] = max(
                    V[i - 1][w],
                    profit[i] + V[i - 1][w - weight[i]]
                );
            else
                V[i][w] = V[i - 1][w];
        }
    }

    printf("Maximum profit = %d\n", V[n][capacity]);

    return 0;
}
