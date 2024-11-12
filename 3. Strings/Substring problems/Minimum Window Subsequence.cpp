#include <bits/stdc++.h>
using namespace std;

/*
    Optimal
        TC -> O(n)
        SC -> O(m)
*/
string minWindow(string s, string t)
{
    int n = s.size(), m = t.size();

    // edge case
    if (m > n || m == 0)
        return "";

    int l, r = 0, minlen = INT_MAX, index;
    string minsub;
    while (r < n)
    {

        index = 0;

        // Move forward
        while (r < n)
        {
            if (s[r] == t[index])
                index++;
            if (index == m)
                break;
            r++;
        }

        if (r == n)
            break;

        // Move backward
        l = r;
        index = m - 1;
        while (l >= 0)
        {
            if (s[l] == t[index])
                index--;
            if (index < 0)
                break;
            l--;
        }

        // store minlength and minsub
        if (r - l + 1 < minlen)
        {
            minlen = r - l + 1;
            minsub = s.substr(l, minlen);
        }
        r = l + 1;
    }
    return minsub;
}