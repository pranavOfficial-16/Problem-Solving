#include <bits/stdc++.h>
using namespace std;

/*
    Optimal
        TC -> O(n)
        SC -> O(n)
*/

/*
  Steps:
    1. Reverse the infix expression and swap the brackets.
    2. Convert the modified infix expression to postfix.
    3. Reverse the postfix expression to get the prefix.
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
string infixToPrefix(string s)
{
    int n = s.size();
    reverse(s.begin(), s.end()); // step 1
    for (int i = 0; i < n; i++)
    {
        if (s[i] == '(')
            s[i] = ')';
        else if (s[i] == ')')
            s[i] = '(';
    }
    string ans;
    stack<char> st;
    for (int i = 0; i < s.size(); i++) // step 2
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
            while (!st.empty() && s[i] == '^' && priority(s[i]) <= priority(st.top()) ||
                   !st.empty() && s[i] != '^' && priority(s[i]) < priority(st.top()))
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
    reverse(ans.begin(), ans.end()); // step 3
    return ans;
}