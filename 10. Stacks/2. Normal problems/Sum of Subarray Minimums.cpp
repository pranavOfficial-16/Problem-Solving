#include <bits/stdc++.h>
using namespace std;

/*
    Optimal
        TC -> O(5n)
        SC -> O(5n)
*/
#include <bits/stdc++.h>
using namespace std;
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
int sumSubarrayMins(vector<int> &arr)
{
    int n = arr.size();
    vector<int> nse = nextSmallerElement(arr, n);
    vector<int> pse = previousSmallerElement(arr, n);
    long long left, right, total = 0, mod = 1e9 + 7;
    for (int i = 0; i < n; i++)
    {
        left = i - pse[i];
        right = nse[i] - i;
        total = (total + (left * right % mod) * arr[i] % mod) % mod;
    }
    return total;
}
int main()
{
    vector<int> arr = {3, 1, 2, 4};
    vector<int> nse = nextSmallerElement(arr, 4);
    vector<int> pse = previousSmallerElement(arr, 4);
    for (auto &i : nse)
        cout << i << " ";
    cout << endl;
    for (auto &i : pse)
        cout << i << " ";
    cout << endl;
    cout << sumSubarrayMins(arr);
}