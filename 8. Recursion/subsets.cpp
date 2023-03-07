// Subsets ( important )
// Subsets are basically for numbers

// Method-1 - using recusion and 2d array ( Return subsets of an array )
// #include <bits/stdc++.h>
// using namespace std;
// int subset(int input[], int n, int output[][20])
// {
//     if (n == 0)
//     {
//         output[0][0] = 0;
//         return 1;
//     }

//     int smalloutputsize = subset(input + 1, n - 1, output);
//     int i, j;
//     for (i = 0; i < smalloutputsize; i++)
//     {
//         // storing size at column 0
//         output[i + smalloutputsize][0] = output[i][0] + 1;
//         // storing value at column 1
//         output[i + smalloutputsize][1] = input[0];
//     }
//     // storing value from column 2
//     for (i = 0; i < smalloutputsize; i++)
//     {
//         for (j = 1; j < output[i + smalloutputsize][0]; j++)
//         {
//             output[i + smalloutputsize][j + 1] = output[i][j];
//         }
//     }
//     return 2 * smalloutputsize;
// }
// int main()
// {
//     int input[20], length, output[50][20];
//     cin >> length;
//     for (int i = 0; i < length; i++)
//         cin >> input[i];

//     int size = subset(input, length, output);

//     for (int i = 0; i < size; i++)
//     {
//         for (int j = 1; j <= output[i][0]; j++)
//         {
//             cout << output[i][j] << " ";
//         }
//         cout << endl;
//     }
// }

// Method-2 - Efficient way using vectors ( print all the subsets of an array )
// #include <bits/stdc++.h>
// using namespace std;
// void solve(vector<int> nums, vector<int> output, int index, vector<vector<int>> &ans)
// {
//     // base case
//     if (index >= nums.size())
//     {
//         ans.push_back(output);
//         return;
//     }

//     // exclude
//     solve(nums, output, index + 1, ans);

//     // include
//     output.push_back(nums[index]);
//     solve(nums, output, index + 1, ans);
// }
// void subsets(vector<int> &nums)
// {
//     vector<vector<int>> ans;
//     vector<int> output;
//     int index = 0;
//     solve(nums, output, index, ans);
//     for (vector<int> vect1D : ans)
//     {
//         for (int x : vect1D)
//         {
//             cout << x << " ";
//         }
//         cout << endl;
//     }
// }
// int main()
// {
//     vector<int> nums;
//     int n;
//     cin >> n;
//     int a;
//     for (int i = 0; i < n; i++)
//     {
//         cin >> a;
//         nums.push_back(a);
//     }
//     subsets(nums);
//     return 0;
// }

// Method-3 - Efficient way using vectors ( return subsets of an array )
#include <bits/stdc++.h>
using namespace std;
void solve(vector<int> nums, vector<int> output, int index, vector<vector<int>> &ans)
{
    // base case
    if (index >= nums.size())
    {
        ans.push_back(output);
        return;
    }

    // exclude
    solve(nums, output, index + 1, ans);

    // include
    output.push_back(nums[index]);
    solve(nums, output, index + 1, ans);
}
vector<vector<int>> subsets(vector<int> &nums)
{
    vector<vector<int>> ans;
    vector<int> output;
    int index = 0;
    solve(nums, output, index, ans);
    return ans;
}
int main()
{
    vector<int> nums;
    int n;
    cin >> n;
    int a;
    for (int i = 0; i < n; i++)
    {
        cin >> a;
        nums.push_back(a);
    }
    vector<vector<int>> v = subsets(nums);
    for (vector<int> vect1D : v)
    {
        for (int x : vect1D)
        {
            cout << x << " ";
        }
        cout << endl;
    }
    return 0;
}