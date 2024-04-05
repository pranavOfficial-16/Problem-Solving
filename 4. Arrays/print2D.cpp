// Print the 0th row from input n times, 1st row n-1 times…..(n-1)th row will be printed 1 time.
#include <iostream>
using namespace std;
void print2DArray(int a[][50], int row, int col)
{
    for (int i = 0; i < row; i++)
    {
        int n = row - i;
        while (n != 0)
        {
            for (int j = 0; j < col; j++)
                cout << a[i][j] << " ";
            n--;
            cout << endl;
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
    print2DArray(a, row, col);
    cout<<
    return 0;
}