#include <bits/stdc++.h>
using namespace std;

/*
    Optimal
        TC -> O(2n)
        SC -> O(k)
*/
int kDistinctChars(int k, string &str)
{
    int n = str.size();
    unordered_map<char, int> distelements;
    int l = 0, r = 0, maxlen = 0;
    while (r < n)
    {
        distelements[str[r]]++;
        while (distelements.size() > k)
        {
            distelements[str[l]]--;
            if (distelements[str[l]] == 0)
                distelements.erase(str[l]);
            l++;
        }
        maxlen = max(maxlen, r - l + 1);
        r++;
    }
    return maxlen;
}