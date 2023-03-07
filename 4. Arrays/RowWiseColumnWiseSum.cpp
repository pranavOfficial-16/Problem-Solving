#include <iostream>
using namespace std;
void RowWiseColumnWiseSum(int a[][50], int row, int col)
{
    // Row wise sum
    int sum = 0;
    cout << "Row Sum : ";
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            sum += a[i][j];
        }
        cout << sum << " ";
        sum = 0;
    }
    cout << endl;

    // Column wise sum
    cout << "Column Sum : ";
    for (int i = 0; i < col; i++)
    {
        for (int j = 0; j < row; j++)
        {
            sum += a[j][i];
        }
        cout << sum << " ";
        sum = 0;
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
    RowWiseColumnWiseSum(a, row, col);
    return 0;
}