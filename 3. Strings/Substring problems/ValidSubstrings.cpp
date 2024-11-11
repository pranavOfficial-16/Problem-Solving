#include <bits/stdc++.h>
using namespace std;

// optimal - 2 pointers approach
vector<pair<int, int>> validSubstrings(string k)
{
    vector<pair<int, int>> res;
    int n = k.size();
    if (n < 3)
        return res;

    int start = 0, end = 1;
    while (end < n)
    {
        if (k[start] == k[end])
            end++;
        else
        {
            if (end - start >= 3)
                res.emplace_back(start, end - 1);
            start = end;
            end++;
        }
    }
    if (end - start >= 3)
        res.emplace_back(start, end);
    return res;
}
int main()
{
    string k;
    cout << "Enter a string: ";
    cin >> k;

    vector<pair<int, int>> result = validSubstrings(k);

    cout << "Valid substrings with 3 or more repeated characters:\n";
    for (const auto &p : result)
        cout << "[" << p.first << ", " << p.second << ")\n";

    return 0;
}