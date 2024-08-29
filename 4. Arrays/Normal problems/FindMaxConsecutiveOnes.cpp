#include <bits/stdc++.h>
using namespace std;
int findMaxConsecutiveOnes(vector<int> &nums)
{
    int count = 0, maxi = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] == 0)
            count = 0;
        else
        {
            count++;
            maxi = max(maxi, count);
        }
    }
    return maxi;
}
int main()
{
    int n;
    cin >> n;
    vector<int> v(n);
    int temp;
    for (int i = 0; i < n; i++)
    {
        cin >> temp;
        v.push_back(temp);
    }
    cout << findMaxConsecutiveOnes(v);
    return 0;
}