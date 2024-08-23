#include <bits/stdc++.h>
using namespace std;
int maxelement(vector<vector<int>> &mat, int n, int m, int mid)
{
    vector<int> ans(n);
    for (int i = 0; i < n; i++)
        ans[i] = mat[i][mid];
    int maxi = INT_MIN, index;
    for (int i = 0; i < n; i++)
    {
        if (maxi < ans[i])
        {
            maxi = ans[i];
            index = i;
        }
    }
    return index;
}
vector<int> findPeakGrid(vector<vector<int>> &mat)
{
    int n = mat.size(), m = mat[0].size();
    int low = 0, high = m - 1, row, left, right;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        row = maxelement(mat, n, m, mid);
        left = mid - 1 >= 0 ? mat[row][mid - 1] : -1;
        right = mid + 1 < m ? mat[row][mid + 1] : -1;
        if (mat[row][mid] > left && mat[row][mid] > right)
            return {row, mid};
        else if (mat[row][mid] < left)
            high = mid - 1;
        else
            low = mid + 1;
    }
    return {-1, -1};
}