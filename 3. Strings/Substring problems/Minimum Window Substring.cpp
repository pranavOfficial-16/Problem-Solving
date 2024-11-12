#include <bits/stdc++.h>
using namespace std;

/*
    Bruteforce
        TC -> O(n^2)
        SC -> O(256)
*/
string minWindow(string s, string t)
{
    int n = s.size(), m = t.size();
    int minlen = INT_MAX, sIndex = -1;
    for (int i = 0; i < n; i++)
    {
        int hash[256] = {0}, count = 0;
        for (int j = 0; j < m; j++)
            hash[t[j]]++;

        for (int j = 0; j < n; j++)
        {
            if (hash[s[j]] > 0)
                count++;
            hash[s[j]]--;
            if (count == m)
            {
                if (j - i + 1 < minlen)
                {
                    minlen = j - i + 1;
                    sIndex = i;
                    break;
                }
            }
        }
    }
    return s.substr(sIndex, minlen);
}

/*
    Optimal
        TC -> O(2n) + O(m)
        SC -> O(256)
*/
string minWindow(string s, string t)
{
    int n = s.size(), m = t.size();
    int minlen = INT_MAX, sIndex = -1, count = 0, l = 0, r = 0;
    unordered_map<char, int> mpp;

    for (int i = 0; i < m; i++)
        mpp[t[i]]++;

    while (r < n)
    {
        if (mpp[s[r]] > 0)
            count++;
        mpp[s[r]]--;
        while (count == m)
        {
            if (r - l + 1 < minlen)
            {
                minlen = r - l + 1;
                sIndex = l;
            }
            mpp[s[l]]++;
            if (mpp[s[l]] > 0)
                count--;
            l++;
        }
        r++;
    }
    return sIndex == -1 ? "" : s.substr(sIndex, minlen);
}