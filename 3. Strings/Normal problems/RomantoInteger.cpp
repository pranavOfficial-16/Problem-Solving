#include <bits/stdc++.h>
using namespace std;
int romanToInt(string s)
{
    int n = s.size(), i = 0, ans = 0;
    while (i < n)
    {
        if (s[i] == 'I')
        {
            if (i < n && s[i + 1] == 'V')
            {
                // 4
                i++;
                ans += 4;
            }
            else if (i < n && s[i + 1] == 'X')
            {
                // 9
                i++;
                ans += 9;
            }
            else
            {
                // 1
                ans += 1;
            }
        }
        else if (s[i] == 'X')
        {
            if (i < n && s[i + 1] == 'L')
            {
                // 40
                i++;
                ans += 40;
            }
            else if (i < n && s[i + 1] == 'C')
            {
                // 90
                i++;
                ans += 90;
            }
            else
            {
                // 10
                ans += 10;
            }
        }
        else if (s[i] == 'C')
        {
            if (i < n && s[i + 1] == 'D')
            {
                // 400
                i++;
                ans += 400;
            }
            else if (i < n && s[i + 1] == 'M')
            {
                // 900
                i++;
                ans += 900;
            }
            else
            {
                // 100
                ans += 100;
            }
        }
        else if (s[i] == 'V')
        {
            // 5
            ans += 5;
        }
        else if (s[i] == 'L')
        {
            // 50
            ans += 50;
        }
        else if (s[i] == 'D')
        {
            // 500
            ans += 500;
        }
        else if (s[i] == 'M')
        {
            // 1000
            ans += 1000;
        }
        i++;
    }
    return ans;
}