#include <bits/stdc++.h>
using namespace std;
bool isIsomorphic(string s, string t)
{

    if (s.size() != t.size())
        return false;

    unordered_map<char, char> mpp;
    unordered_set<char> mappedchar;

    for (int i = 0; i < s.size(); i++)
    {
        char c1 = s[i], c2 = t[i];

        // if s[i] is in the map
        if (mpp.find(c1) != mpp.end())
        {
            if (mpp[c1] != c2)
                return false;
        }
        else
        {
            // if t[i] is in the set
            if (mappedchar.find(c2) != mappedchar.end())
                return false;
                
            mpp[c1] = c2;
            mappedchar.insert(c2);
        }
    }
    return true;
}