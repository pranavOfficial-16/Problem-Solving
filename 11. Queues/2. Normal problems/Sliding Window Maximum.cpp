#include <bits/stdc++.h>
using namespace std;

/*
    Optimal
        TC -> O(2n)
        SC -> O(k) + O(n-k)
*/
vector<int> maxSlidingWindow(vector<int> &nums, int k)
{
    vector<int> max_elements;
    deque<int> dq;
    int n = nums.size();

    for (int i = 0; i < n; i++)
    {
        if (!dq.empty() && dq.front() <= i - k)
            dq.pop_front();
        while (!dq.empty() && nums[dq.back()] <= nums[i])
            dq.pop_back();
        dq.push_back(i);
        if (i >= k - 1)
            max_elements.push_back(nums[dq.front()]);
    }
    return max_elements;
}