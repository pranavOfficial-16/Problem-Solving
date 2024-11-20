#include <bits/stdc++.h>
#include <stack>
using namespace std;
bool isBalanced(string s)
{
    stack<char> st;
    for (char c : s)
    {
        if (c == '(' || c == '[' || c == '{')
            st.push(c);
        else
        {
            if (st.empty())
                return false;
            if ((c == ')' && st.top() == '(') ||
                (c == ']' && st.top() == '[') ||
                (c == '}' && st.top() == '{'))
            {
                st.pop();
            }
            else
                return false;
        }
    }
    return st.empty();
}
int main()
{
    string input;
    cin >> input;
    cout << ((isBalanced(input)) ? "true" : "false");
}