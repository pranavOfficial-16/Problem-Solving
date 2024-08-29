#include<iostream>
using namespace std;
void wavePrint(int a[][50], int row, int col)
{
    int k = 0;
    for (int i = 0; i < col; i++)
    {
        for (int j = 0; j < row; j++)
        {
            if (i % 2 == 0)
                cout << a[j][i] << " ";
            else
                cout << a[row - j - 1][i] << " ";
        }
    }
}
int main()
{
    int a[50][50];
    int row, col;
    cin >> row >> col;
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cin >> a[i][j];
        }
    }
    wavePrint(a,row,col);
    return 0;
}