#include <bits/stdc++.h>
using namespace std;

/*
    Optimal
        TC -> O(n)
        SC -> O(n)
*/
vector<int> nextGreaterElement(vector<int> &nums1, vector<int> &nums2)
{
    stack<int> st; // Monotonic stack (Decreasing)
    vector<int> ans;
    unordered_map<int, int> mpp;
    int m = nums1.size(), n = nums2.size();
    for (int i = n - 1; i >= 0; i--)
    {
        while (!st.empty() && st.top() <= nums2[i])
            st.pop();
        if (st.empty())
            mpp[nums2[i]] = -1;
        else
            mpp[nums2[i]] = st.top();
        st.push(nums2[i]);
    }
    for (int i = 0; i < m; i++)
        ans.push_back(mpp[nums1[i]]);
    return ans;
}