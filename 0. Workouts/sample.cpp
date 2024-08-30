#include <bits/stdc++.h>
using namespace std;
int beauty(string s, int low, int high)
{
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
int main()
{
    cout << beauty("aaab", 0, 3);
}