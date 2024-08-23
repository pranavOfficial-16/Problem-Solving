#include <bits/stdc++.h>
using namespace std;

// method - 1

// bool binarySearch(vector<vector<int>> &matrix, int row, int colsize, int target)
// {
//     vector<int> ans(colsize);
//     for (int i = 0; i < colsize; i++)
//         ans[i] = matrix[row][i];
//     int low = 0, high = colsize - 1;
//     while (low <= high)
//     {
//         int mid = low + (high - low) / 2;
//         if (ans[mid] == target)
//             return true;
//         else if (target < ans[mid])
//             high = mid - 1;
//         else
//             low = mid + 1;
//     }
//     return false;
// }
// bool searchMatrix(vector<vector<int>> &matrix, int target)
// {
//     int n = matrix.size(), m = matrix[0].size();
//     for (int i = 0; i < n; i++)
//     {
//         if (target <= matrix[i][m - 1])
//             return binarySearch(matrix, i, m, target);
//     }
//     return false;
// }

// method - 2

bool searchMatrix(vector<vector<int>> &matrix, int target)
{
    int n = matrix.size();
    int m = matrix[0].size();

    // apply binary search:
    int low = 0, high = n * m - 1;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        int row = mid / m, col = mid % m;
        if (matrix[row][col] == target)
            return true;
        else if (matrix[row][col] < target)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return false;
}

int main()
{
    vector<vector<int>> matrix = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}};
    searchMatrix(matrix, 8) == true ? cout << "true\n" : cout << "false\n";
}
