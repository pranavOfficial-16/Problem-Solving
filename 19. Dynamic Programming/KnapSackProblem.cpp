#include <bits/stdc++.h>
using namespace std;

// bruteforce
int knapsack(int *weight, int *values, int n, int maxWeight)
{
    // Base case
    if (n == 0 || maxWeight == 0)
        return 0;

    if (weight[0] > maxWeight)
        return knapsack(weight + 1, values + 1, n - 1, maxWeight);

    // Recursive calls
    int x = knapsack(weight + 1, values + 1, n - 1, maxWeight - weight[0]) + values[0];
    int y = knapsack(weight + 1, values + 1, n - 1, maxWeight);

    return max(x, y);
}

// memoization
int knapsack(int *weights, int *values, int n, int maxWeight, int **output)
{
    if (maxWeight == 0 || n == 0)
        return 0;

    if (output[n][maxWeight] != -1)
        return output[n][maxWeight];

    int ans;
    if (maxWeight < weights[0])
        ans = knapsack(weights + 1, values + 1, n - 1, maxWeight, output);
    else
    {
        int x = knapsack(weights + 1, values + 1, n - 1, maxWeight - weights[0], output) + values[0];
        int y = knapsack(weights + 1, values + 1, n - 1, maxWeight, output);
        ans = max(x, y);
    }

    output[n][maxWeight] = ans;

    return output[n][maxWeight];
}
int knapsack(int *weight, int *values, int n, int maxWeight)
{
    int **output = new int *[n + 1];
    for (int i = 0; i <= n; i++)
    {
        output[i] = new int[maxWeight + 1];
        for (int j = 0; j <= maxWeight; j++)
            output[i][j] = -1;
    }
    return knapsack(weight, values, n, maxWeight, output);
}

// dp
int knapsack(int *weights, int *values, int n, int maxWeight)
{
    int **output = new int *[n + 1];
    for (int i = 0; i <= n; i++)
        output[i] = new int[maxWeight + 1];

    for (int i = 0; i <= n; i++)
        output[i][0] = 0;

    for (int i = 0; i <= maxWeight; i++)
        output[0][i] = 0;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= maxWeight; j++)
        {
            if (j < weights[n - i])
                output[i][j] = output[i - 1][j];
            else
                output[i][j] = max(output[i - 1][j - weights[n - i]] + values[n - i], output[i - 1][j]);
        }
    }
    return output[n][maxWeight];
}