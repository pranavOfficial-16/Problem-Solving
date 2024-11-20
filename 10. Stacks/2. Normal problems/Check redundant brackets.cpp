#include <bits/stdc++.h>
using namespace std;
bool checkRedundantBrackets(string str)
{
    stack<int> s;
    for (int i = 0; i < str.size(); i++)
    {
        if (str[i] == ')')
        {
            char top = s.top();
            s.pop();
            bool flag = true;
            while (!s.empty() && top != '(')
            {
                if (top == '+' || top == '-' || top == '*' || top == '/')
                    flag = false;
                top = s.top();
                s.pop();
            }
            if (flag == true)
                return true;
        }
        else
            s.push(str[i]);
    }
    return false;
}

int main()
{
    string input;
    cin >> input;
    cout << ((checkRedundantBrackets(input)) ? "true" : "false");
}