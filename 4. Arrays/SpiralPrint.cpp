#include <iostream>
using namespace std;
void spiralPrint(int a[][50], int m, int n)
{
    int row_start = 0, column_start = 0;
    while (row_start < m && column_start < n)
    {
        for (int i = column_start; i < n; i++)
            cout << a[row_start][i] << " ";
        row_start++;
        for (int i = row_start; i < m; ++i)
            cout << a[i][n - 1] << " ";
        n--;
        if (row_start < m)
        {
            for (int i = n - 1; i >= column_start; --i)
                cout << a[m - 1][i] << " ";
            m--;
        }
        if (column_start < n)
        {
            for (int i = m - 1; i >= row_start; --i)
                cout << a[i][column_start] << " ";
            column_start++;
        }
    }
}
int main()
{
    int a[50][50];
    int m, n;
    cin >> m >> n;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> a[i][j];
        }
    }
    spiralPrint(a, m, n);
    return 0;
}