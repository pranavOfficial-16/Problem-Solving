#include <bits/stdc++.h>
using namespace std;
void solve(int index, int sum, vector<int> &arr, vector<int> &ans, int n)
{
    // base case
    if (index == arr.size())
    {
        ans.push_back(sum);
        return;
    }

    // exclude
    solve(index + 1, sum, arr, ans, n);

    // include
    solve(index + 1, sum + arr[index], arr, ans, n);
}
vector<int> subsetSums(vector<int> arr, int n)
{
    vector<int> ans;
    solve(0, 0, arr, ans, n);
    return ans;
}