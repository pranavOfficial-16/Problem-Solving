#include <bits/stdc++.h>
using namespace std;
string frequencySort(string s)
{
    // Count the frequency of each character using a map
    map<char, int> frequencyMap;
    for (char c : s)
        frequencyMap[c]++;

    // Transfer the frequency data from the map to a vector of pairs
    vector<pair<char, int>> freqVec(frequencyMap.begin(), frequencyMap.end());

    // Sort the vector based on frequency in descending order
    sort(freqVec.begin(), freqVec.end(), [](pair<char, int> &a, pair<char, int> &b)
         { return a.second > b.second; });

    // Construct the result string based on sorted data
    string result;
    for (auto &p : freqVec)
    {
        result += string(p.second, p.first);
    }

    return result;
}
int main()
{
    string s = "tree";
    cout << frequencySort(s);
}