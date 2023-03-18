#include <bits/stdc++.h>
using namespace std;
void solve(int index, int sum, vector<int> nums, vector<int> &output, int k)
{
    // base case
    if (index == nums.size())
    {
        if (sum == k)
            output.push_back(sum);
        return;
    }

    // exclude
    solve(index + 1, sum, nums, output, k);

    // include
    solve(index + 1, sum + nums[index], nums, output, k);
}
void subsets(vector<int> &nums, int k)
{
    vector<int> output;
    solve(0, 0, nums, output, k);
    cout << output.size() << endl;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int k;
        cin >> k;
        vector<int> nums(n);
        for (int i = 0; i < n; i++)
            cin >> nums[i];
        subsets(nums, k);
    }
    return 0;
}