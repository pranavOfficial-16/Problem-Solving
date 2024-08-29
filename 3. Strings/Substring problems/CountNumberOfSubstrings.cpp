#include <bits/stdc++.h>
using namespace std;

// brute force

// int distinct(string s, int left, int right)
// {
//     set<char> distelemets;
//     for (int i = left; i <= right; i++)
//         distelemets.insert(s[i]);
//     return distelemets.size();
// }
// int substrCount(string s, int k)
// {
//     int count = 0, n = s.size();
//     for (int i = 0; i < n; i++)
//     {
//         for (int j = i; j < n; j++)
//         {
//             if (distinct(s, i, j) == k)
//                 count++;
//         }
//     }
//     return count;
// }


// Optimal -> TC - O(N), SC - O(1)

int countSubstringsWithAtMostKDistinct(string s, int k)
{
    int n = s.size();
    vector<int> freq(26, 0);
    int left = 0, count = 0, distinctCount = 0;
    for (int right = 0; right < n; right++)
    {
        freq[s[right] - 'a']++;
        if (freq[s[right] - 'a'] == 1)
            distinctCount++;

        while (distinctCount > k)
        {
            freq[s[left] - 'a']--;
            if (freq[s[left] - 'a'] == 0)
                distinctCount--;
            left++;
        }

        // if count <= k
        count += right - left + 1;
    }
    return count;
}
int substrCount(string s, int k)
{
    // Handle non-positive k values
    if (k <= 0)
        return 0;

    int equalToKdistinctElements = countSubstringsWithAtMostKDistinct(s, k) - countSubstringsWithAtMostKDistinct(s, k - 1);
    return equalToKdistinctElements;
}
int main()
{
    string s = "abaaca";
    int k = 1;
    cout << substrCount(s, k);
    return 0;
}