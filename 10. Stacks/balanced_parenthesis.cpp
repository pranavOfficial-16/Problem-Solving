#include <bits/stdc++.h>
#include <stack>
using namespace std;
bool isBalanced(string s)
{
    stack<char> st;
    int i;
    for (i = 0; i < s.size(); i++)
    {
        if (s[i] == '(' || s[i] == '[' || s[i] == '{')
            st.push(s[i]);
        if (s[i] == ')')
        {
            if (st.empty())
                return false;
            if (st.top() == '(')
                st.pop();
            else
                return false;
        }
        if (s[i] == ']')
        {
            if (st.empty())
                return false;
            if (st.top() == ']')
                st.pop();
            else
                return false;
        }
        if (s[i] == '}')
        {
            if (st.empty())
                return false;
            if (st.top() == '}')
                st.pop();
            else
                return false;
        }
    }
    if (i == s.size() && st.empty())
        return true;
    return false;
}
int main()
{
    string input;
    cin >> input;
    cout << ((isBalanced(input)) ? "true" : "false");
}