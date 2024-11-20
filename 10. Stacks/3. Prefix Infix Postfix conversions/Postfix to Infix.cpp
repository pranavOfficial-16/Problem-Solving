#include <bits/stdc++.h>
using namespace std;

/*
    Optimal
        TC -> O(n)
        SC -> O(n)
*/
string PostfixToInfix(string s)
{
    int n = s.size();
    stack<string> st;
    string t1, t2, temp;
    for (int i = 0; i < n; i++)
    {
        if ((s[i] >= 'A' && s[i] <= 'Z') ||
            (s[i] >= 'a' && s[i] <= 'z') ||
            (s[i] >= '0' && s[i] <= '9'))
            st.push(string(1, s[i]));
        else
        {
            t1 = st.top();
            st.pop();
            t2 = st.top();
            st.pop();
            temp = "(" + t2 + s[i] + t1 + ")";
            st.push(temp);
        }
    }
    return st.top();
}