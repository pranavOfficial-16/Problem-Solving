#include <bits/stdc++.h>
using namespace std;

/*
    Bruteforce
        TC -> O(n^2)
        SC -> O(1)
*/
int totalFruit(vector<int> &fruits)
{
    int maxlen = 0, n = fruits.size();
    for (int i = 0; i < n; i++)
    {
        set<int> st;
        for (int j = i; j < n; j++)
        {
            st.insert(fruits[j]);
            if (st.size() <= 2)
                maxlen = max(maxlen, j - i + 1);
            else
                break;
        }
    }
    return maxlen;
}

/*
    Better
        TC -> O(2n)
        SC -> O(1)
*/
int totalFruit(vector<int> &fruits)
{
    int l = 0, r = 0, maxlen = 0, n = fruits.size();
    map<int, int> mpp;
    while (r < n)
    {
        mpp[fruits[r]]++;
        if (mpp.size() > 2)
        {
            while (mpp.size() > 2)
            {
                mpp[fruits[l]]--;
                if (mpp[fruits[l]] == 0)
                    mpp.erase(fruits[l]);
                l++;
            }
        }
        if (mpp.size() <= 2)
            maxlen = max(maxlen, r - l + 1);
        r++;
    }
    return maxlen;
}

/*
    Optimal
        TC -> O(n)
        SC -> O(1)
*/
int totalFruit(vector<int> &fruits)
{
    int l = 0, r = 0, maxlen = 0, n = fruits.size();
    map<int, int> mpp;
    while (r < n)
    {
        mpp[fruits[r]]++;
        if (mpp.size() > 2)
        {
            mpp[fruits[l]]--;
            if (mpp[fruits[l]] == 0)
                mpp.erase(fruits[l]);
            l++;
        }
        if (mpp.size() <= 2)
            maxlen = max(maxlen, r - l + 1);
        r++;
    }
    return maxlen;
}