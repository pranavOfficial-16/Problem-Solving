#include <bits/stdc++.h>
using namespace std;

/*
    Optimal
        TC -> O(2n)
        SC -> O(2n) 
*/
int priority(char value)
{
    if (value == '^')
        return 3;
    else if (value == '*' || value == '/')
        return 2;
    else if (value == '+' || value == '-')
        return 1;
    else
        return -1;
}
string infixToPostfix(string s)
{
    string ans;
    stack<char> st;
    for (int i = 0; i < s.size(); i++)
    {
        if ((s[i] >= 'A' && s[i] <= 'Z') ||
            (s[i] >= 'a' && s[i] <= 'z') ||
            (s[i] >= '0' && s[i] <= '9'))
            ans += s[i];
        else if (s[i] == '(')
            st.push(s[i]);
        else if (s[i] == ')')
        {
            while (!st.empty() && st.top() != '(')
            {
                ans += st.top();
                st.pop();
            }
            st.pop(); // popping out '('
        }
        else
        {
            while (!st.empty() && priority(s[i]) <= priority(st.top()))
            {
                ans += st.top();
                st.pop();
            }
            st.push(s[i]);
        }
    }
    while (!st.empty())
    {
        ans += st.top();
        st.pop();
    }
    return ans;
}