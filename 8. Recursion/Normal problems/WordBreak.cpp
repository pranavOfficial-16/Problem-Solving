#include <bits/stdc++.h>
using namespace std;
// Bruteforce - recursion method (Not optimized solution)
bool brute(string s, unordered_set<string> &set)
{
    // base case
    if (s.size() == 0)
        return true;

    for (int i = 0; i < s.length(); i++)
    {
        if (set.count(s.substr(0, i + 1)) && brute(s.substr(i + 1), set))
            return true;
    }
    return false;
}
bool wordBreak(string s, vector<string> &wordDict)
{
    unordered_set<string> set(wordDict.begin(), wordDict.end());
    return brute(s, set);
}