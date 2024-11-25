#include <bits/stdc++.h>
using namespace std;
/*
    Optimal
        TC -> O(2n) + O(k)
        SC -> O(2n)
*/
string removeKdigits(string num, int k)
{
    int n = num.size();
    stack<int> st; // monotonic increasing stack

    for (int i = 0; i < n; i++)
    {
        int curr = num[i] - '0';
        while (!st.empty() && k > 0 && st.top() > curr)
        {
            st.pop();
            k--;
        }
        st.push(curr);
    }

    // Remove remaining digits if k > 0
    while (k > 0 && !st.empty())
    {
        st.pop();
        k--;
    }

    // Construct the result string from the stack
    string res;
    while (!st.empty())
    {
        res += st.top() + '0'; // Convert integer to character
        st.pop();
    }
    reverse(res.begin(), res.end()); // Reverse the result to get the correct order

    // Remove leading zeros
    int i = 0;
    while (i < res.size() && res[i] == '0')
        i++;

    res = res.substr(i);

    // If the result is empty, return "0"
    return res.empty() ? "0" : res;
}