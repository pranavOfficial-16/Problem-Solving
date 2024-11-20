#include <bits/stdc++.h>
using namespace std;
int countBracketReversals(string s)
{
    int n = s.size();
    if (n % 2 == 1)
        return -1;
    int count = 0;
    stack<int> st;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == '{')
            st.push(s[i]);
        else
        {
            if (!st.empty())
                st.pop();
            else{
                st.push('{');
                count++;
            }
        }
    }
    count+=st.size()/2;
    return count;
}
int main()
{
    string input;
    cin >> input;
    cout << countBracketReversals(input);
}