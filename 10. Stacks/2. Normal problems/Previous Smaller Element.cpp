#include <bits/stdc++.h>
using namespace std;

/*
    Optimal
        TC -> O(n)
        SC -> O(n)
*/
vector<int> previousSmallerElement(vector<int> &arr, int n)
{
    stack<int> st; // Monotonic stack (Increasing)
    vector<int> ans;
    for (int i = 0; i < n; i++)
    {
        while (!st.empty() && st.top() > arr[i])
            st.pop();
        if (st.empty())
            ans.push_back(-1);
        else
            ans.push_back(st.top());
        st.push(arr[i]);
    }
    return ans;
}