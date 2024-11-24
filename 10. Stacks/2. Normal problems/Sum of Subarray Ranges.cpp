/*
    Optimal
        TC -> O(10n)
        SC -> O(10n)
*/
#include <bits/stdc++.h>
using namespace std;
vector<int> nextLargestElement(vector<int> &arr, int n)
{
    stack<int> st; // Monotonic stack (Decreasing)
    vector<int> ans;
    for (int i = n - 1; i >= 0; i--)
    {
        while (!st.empty() && arr[st.top()] <= arr[i])
            st.pop();
        if (st.empty())
            ans.push_back(n);
        else
            ans.push_back(st.top());
        st.push(i);
    }
    reverse(ans.begin(), ans.end());
    return ans;
}
vector<int> previousLargestElement(vector<int> &arr, int n)
{
    stack<int> st; // Monotonic stack (Decreasing)
    vector<int> ans;
    for (int i = 0; i < n; i++)
    {
        while (!st.empty() && arr[st.top()] < arr[i])
            st.pop();
        if (st.empty())
            ans.push_back(-1);
        else
            ans.push_back(st.top());
        st.push(i);
    }
    return ans;
}
long long sumSubarrayMaxs(vector<int> &arr)
{
    int n = arr.size();
    vector<int> nle = nextLargestElement(arr, n);
    vector<int> ple = previousLargestElement(arr, n);
    long long left, right, total = 0;
    for (int i = 0; i < n; i++)
    {
        left = i - ple[i];
        right = nle[i] - i;
        total = total + (left * right * arr[i]);
    }
    return total;
}
vector<int> nextSmallerElement(vector<int> &arr, int n)
{
    stack<int> st; // Monotonic stack (Increasing)
    vector<int> ans;
    for (int i = n - 1; i >= 0; i--)
    {
        while (!st.empty() && arr[st.top()] >= arr[i])
            st.pop();
        if (st.empty())
            ans.push_back(n);
        else
            ans.push_back(st.top());
        st.push(i);
    }
    reverse(ans.begin(), ans.end());
    return ans;
}
vector<int> previousSmallerElement(vector<int> &arr, int n)
{
    stack<int> st; // Monotonic stack (Increasing)
    vector<int> ans;
    for (int i = 0; i < n; i++)
    {
        while (!st.empty() && arr[st.top()] > arr[i])
            st.pop();
        if (st.empty())
            ans.push_back(-1);
        else
            ans.push_back(st.top());
        st.push(i);
    }
    return ans;
}
long long sumSubarrayMins(vector<int> &arr)
{
    int n = arr.size();
    vector<int> nse = nextSmallerElement(arr, n);
    vector<int> pse = previousSmallerElement(arr, n);
    long long left, right, total = 0;
    for (int i = 0; i < n; i++)
    {
        left = i - pse[i];
        right = nse[i] - i;
        total = total + (left * right * arr[i]);
    }
    return total;
}
long long subArrayRanges(vector<int> &nums)
{
    return sumSubarrayMaxs(nums) - sumSubarrayMins(nums);
}