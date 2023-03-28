#include <bits/stdc++.h>
using namespace std;

// bruteforce
int minCostPath(int **input, int m, int n, int i, int j)
{
    if (i == m - 1 && j == n - 1)
        return input[i][j];

    if (i >= m || j >= n)
        return INT_MAX;

    int x = minCostPath(input, m, n, i, j + 1);
    int y = minCostPath(input, m, n, i + 1, j + 1);
    int z = minCostPath(input, m, n, i + 1, j);

    int ans = min(x, min(y, z)) + input[i][j];
    return ans;
}
int minCostPath(int **input, int m, int n)
{
    return minCostPath(input, m, n, 0, 0);
}

// Memoization
int minCostPath1(int **input, int m, int n, int i, int j, int **output)
{
    if (i == m - 1 && j == n - 1)
        return input[i][j];

    if (i >= m || j >= n)
        return INT_MAX;

    if (output[i][j] != -1)
        return output[i][j];

    int x = minCostPath1(input, m, n, i, j + 1, output);
    int y = minCostPath1(input, m, n, i + 1, j + 1, output);
    int z = minCostPath1(input, m, n, i + 1, j, output);

    int ans = min(x, min(y, z)) + input[i][j];

    output[i][j] = ans;

    return ans;
}

// dp
int minCostPath2(int **input, int m, int n)
{
    int **ans = new int *[m];
    for (int i = 0; i < m; i++)
        ans[i] = new int[n];

    ans[m - 1][n - 1] = input[m - 1][n - 1];

    // Last row
    for (int j = n - 2; j >= 0; j--)
        ans[m - 1][j] = input[m - 1][j] + ans[m - 1][j + 1];

    // Last col
    for (int i = m - 2; i >= 0; i--)
        ans[i][n - 1] = input[i][n - 1] + ans[i + 1][n - 1];

    for (int i = m - 2; i >= 0; i--)
    {
        for (int j = n - 2; j >= 0; j--)
        {
            ans[i][j] = input[i][j] + min(ans[i][j + 1], min(ans[i + 1][j + 1], ans[i + 1][j]));
        }
    }
    return ans[0][0];
}

int main()
{
    int **arr, n, m;
    cin >> n >> m;
    arr = new int *[n];
    for (int i = 0; i < n; i++)
    {
        arr[i] = new int[m];
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> arr[i][j];
        }
    }
    cout << minCostPath(arr, n, m) << endl;
    return 0;
}