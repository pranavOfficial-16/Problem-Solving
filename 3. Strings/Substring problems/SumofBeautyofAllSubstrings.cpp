#include <bits/stdc++.h>
using namespace std;
int beauty(string s, int low, int high)
{
    // edge case -> if the size of substring is 1 then beauty is 0
    if (low == high)
        return 0;

    unordered_map<char, int> mpp;
    // storing string freq in map
    for (int i = low; i <= high; i++)
        mpp[s[i]]++;

    // copying the map to vector pair to sort the map based on value
    vector<pair<char, int>>
        vec(mpp.begin(), mpp.end());

    // sorting in non descending order
    sort(vec.begin(), vec.end(), [](pair<char, int> &a, pair<char, int> &b)
         { return a.second < b.second; });

    // size of vector pair
    int n = vec.size();

    // fetching beauty
    int beauty = vec[n - 1].second - vec[0].second;

    return beauty;
}

// bruteforce
int beautySumBruteforce(string s)
{
    int sum = 0, n = s.size();
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            sum += beauty(s, i, j);
        }
    }
    return sum;
}

// Better
int beautySumBetter(string s)
{
    int n = s.size();

    // edge case (substrings with size<3, their beautysum is always 0)
    if (n < 3)
        return 0;

    int low = 0, high, sum = 0;
    while (low <= n - 3)
    {
        high = low + 2;
        while (high < n)
        {
            sum += beauty(s, low, high);
            high++;
        }
        low++;
    }
    return sum;
}

// Optimal
int beautySumOptimal(string s)
{
    int n = s.size();

    // edge case (substrings with size<3, their beautysum is always 0)
    if (n < 3)
        return 0;

    int sum = 0, lowfreq, highfreq;
    for (int i = 0; i < n; i++)
    {
        unordered_map<char, int> mpp;
        for (int j = i; j < n; j++)
        {
            mpp[s[j]]++;
            lowfreq = INT_MAX;
            highfreq = INT_MIN;
            for (auto &it : mpp)
            {
                lowfreq = min(lowfreq, it.second);
                highfreq = max(highfreq, it.second);
            }
            sum += highfreq - lowfreq;
        }
    }
    return sum;
}
int main()
{

    string s = "aabcb";
    cout << beautySumBruteforce(s) << endl;
    cout << beautySumBetter(s) << endl;
    cout << beautySumOptimal(s) << endl;
}