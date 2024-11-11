#include <bits/stdc++.h>
using namespace std;

// bruteforce
int lengthOfLongestSubstring(string s)
{
    int n = s.size();
    int len = 0, maxlen = 0;
    for (int i = 0; i < n; i++)
    {
        int hash[256] = {0};
        for (int j = i; j < n; j++)
        {
            if (hash[s[j]] == 1)
                break;
            len = j - i + 1;
            maxlen = max(maxlen, len);
            hash[s[j]] = 1;
        }
    }
    return maxlen;
}

// optimal
int lengthOfLongestSubstring(string s)
{
    int n = s.size();
    vector<int> mpp(256, -1);
    int len = 0, maxlen = 0, l = 0, r = 0;
    while (r < n)
    {
        // if it is in the hashmap
        if (mpp[s[r]] != -1)
        {
            // check if the character in the hashmap is in window range
            if (mpp[s[r]] >= l)
                l = mpp[s[r]] + 1;
        }
        len = r - l + 1;
        maxlen = max(maxlen, len);
        mpp[s[r]] = r;
        r++;
    }
    return maxlen;
}