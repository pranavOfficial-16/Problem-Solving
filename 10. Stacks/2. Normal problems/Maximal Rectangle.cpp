#include <bits/stdc++.h>
using namespace std;

/*
    Optimal
        TC -> O(m*n) + O(n * 2m)
        SC -> O(m*n) + O(n)
*/
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
        while (!st.empty() && arr[st.top()] >= arr[i])
            st.pop();
        if (st.empty())
            ans.push_back(-1);
        else
            ans.push_back(st.top());
        st.push(i);
    }
    return ans;
}
int largestRectangleArea(vector<int> &heights)
{
    int n = heights.size();
    vector<int> nse = nextSmallerElement(heights, n);
    vector<int> pse = previousSmallerElement(heights, n);
    int maxi = 0, area;
    for (int i = 0; i < n; i++)
    {
        area = heights[i] * (nse[i] - pse[i] - 1);
        maxi = max(maxi, area);
    }
    return maxi;
}
int maximalRectangle(vector<vector<char>> &matrix)
{
    int n = matrix.size();
    int m = matrix[0].size();
    int sum, area, maxarea = 0;
    vector<vector<int>> prefixsum(n, vector<int>(m, 0));

    // computing all the prefix sums
    for (int j = 0; j < m; j++)
    {
        sum = 0;
        for (int i = 0; i < n; i++)
        {
            sum += matrix[i][j] - '0';
            if (matrix[i][j] - '0' == 0)
                sum = 0;
            prefixsum[i][j] = sum;
        }
    }

    for (int i = 0; i < n; i++)
    {
        area = largestRectangleArea(prefixsum[i]);
        maxarea = max(maxarea, area);
    }
    return maxarea;
}