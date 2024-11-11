#include <bits/stdc++.h>
using namespace std;

/*
    Bruteforce
        TC -> O(n^2)
        SC -> O(1)
*/
int characterReplacement(string s, int k)
{
    int n = s.size();
    int maxfreq = 0, changes, maxlen = 0;
    for (int i = 0; i < n; i++)
    {
        vector<int> hash(26, 0);
        for (int j = i; j < n; j++)
        {
            hash[s[j] - 'A']++;
            maxfreq = max(maxfreq, hash[s[j] - 'A']);
            changes = (j - i + 1) - maxfreq;
            if (changes <= k)
                maxlen = max(maxlen, j - i + 1);
            else
                break;
        }
    }
    return maxlen;
}

/*
    Better
        TC -> O((n+n) * 26)
        SC -> O(26)
*/
int characterReplacement(string s, int k)
{
    int n = s.size();
    int l = 0, r = 0, len, changes, maxlen = 0, maxfreq = 0;
    vector<int> hash(26, 0);
    while (r < n)
    {
        hash[s[r] - 'A']++;
        maxfreq = max(maxfreq, hash[s[r] - 'A']);
        len = r - l + 1;
        changes = len - maxfreq;
        while (changes > k)
        {
            hash[s[r] - 'A']--;
            maxfreq = 0;
            for (int i = 0; i < 26; i++)
                maxfreq = max(maxfreq, hash[i]);
            l++;
        }
        if (changes <= k)
            maxlen = max(maxlen, len);
        r++;
    }
    return maxlen;
}

/*
    Optimal
        TC -> O(n)
        SC -> O(26) 
*/
int characterReplacement(string s, int k)
{
    int n = s.size();
    int l = 0, r = 0, len, changes, maxlen = 0, maxfreq = 0;
    vector<int> hash(26, 0);
    while (r < n)
    {
        hash[s[r] - 'A']++;
        maxfreq = max(maxfreq, hash[s[r] - 'A']);
        len = r - l + 1;
        changes = len - maxfreq;
        if (changes > k)
        {
            hash[s[l] - 'A']--;
            l++;
        }
        if (changes <= k)
            maxlen = max(maxlen, len);
        r++;
    }
    return maxlen;
}