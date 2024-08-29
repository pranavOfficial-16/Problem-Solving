#include <bits/stdc++.h>
using namespace std;
int maxDepth(string s)
{
    int n = s.size();
    int open = 0, close = 0, maxi = 0;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == '(')
            open++;
        else if (s[i] == ')')
        {
            maxi = max(maxi, open - close);
            close++;
        }
        if (isdigit(s[i]))
            maxi = max(maxi, open - close);
    }
    return maxi;
}