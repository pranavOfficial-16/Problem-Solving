#include <bits/stdc++.h>
using namespace std;

int findMaxSquareWithAllZeros(int **arr, int row, int col)
{
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)

            if (arr[i][j] == 1)
                arr[i][j] = 0;
            else
                arr[i][j] = 1;
    }
    int max = 0;
    for (int i = 1; i < row; i++)
    {
        for (int j = 1; j < col; j++)
        {
            if (arr[i][j] == 0)
                continue;
            arr[i][j] = min(arr[i - 1][j], min(arr[i - 1][j - 1], arr[i][j - 1])) + 1;
            if (max < arr[i][j])
                max = arr[i][j];
        }
    }
    return max;
}

int main()
{
    return 0;
}