#include <iostream>
#include <climits>
using namespace std;
void findLargest(int a[][50], int row, int col)
{
    // Row sum
    int rindex;
    int mxr = INT_MIN;
    for (int i = 0; i < row; i++)
    {
        int rsum = 0;
        for (int j = 0; j < col; j++)
        {
            rsum += a[i][j];
        }
        if (rsum > mxr)
        {
            rindex = i;
            mxr = rsum;
        }
    }
    // Column sum
    int cindex;
    int mxc = INT_MIN;
    for (int i = 0; i < col; i++)
    {
        int csum = 0;
        for (int j = 0; j < row; j++)
        {
            csum += a[j][i];
        }
        if (csum > mxc)
        {
            cindex = i;
            mxc = csum;
        }
    }
    if (mxr > mxc)
        cout << "row " << rindex << " " << mxr;
    else if (mxc > mxr)
        cout << "column " << cindex << " " << mxc;
    else
        cout << "row 0 " << mxr;
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
    findLargest(a, row, col);
    return 0;
}