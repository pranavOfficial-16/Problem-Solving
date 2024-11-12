#include <bits/stdc++.h>
using namespace std;

/*
    Bruteforce
        TC -> O(n^2)
        SC -> O(1)
*/
int numberOfSubstrings(string s)
{
    int count = 0;
    int n = s.size();
    for (int i = 0; i < n; i++)
    {
        int hash[3] = {0};
        for (int j = i; j < n; j++)
        {
            hash[s[j] - 'a'] = 1;
            if (hash[0] + hash[1] + hash[2] == 3)
            {
                count += (n - j);
                break;
            }
        }
    }
    return count;
}

/*
    Optimal
        TC -> O(n)
        SC -> O(1)
*/
int numberOfSubstrings(string s)
{
    int n = s.size();
    int count = 0;
    int lastseen[3] = {-1, -1, -1};
    for (int i = 0; i < n; i++)
    {
        lastseen[s[i] - 'a'] = i;
        count += 1 + min(lastseen[0], min(lastseen[1], lastseen[2]));
    }
    return count;
}