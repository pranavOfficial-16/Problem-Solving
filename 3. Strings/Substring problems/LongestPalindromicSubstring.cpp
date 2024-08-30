#include <bits/stdc++.h>
using namespace std;
bool pallindrome(string s, int low, int high)
{
    while (low < high)
    {
        if (s[low] != s[high])
            return false;
        low++;
        high--;
    }
    return true;
}

// bruteforce approach
string longestPalindrome(string s)
{
    int n = s.size(), start = 0, maxi = 0;
    for (int low = 0; low < n; low++)
    {
        for (int high = low; high < n; high++)
        {
            if (pallindrome(s, low, high) && (maxi < high - low + 1))
            {
                start = low;
                maxi = high - low + 1;
            }
        }
    }
    return s.substr(start, maxi);
}

// better approach -> Expand through center, TC-O(N^2)
string longestPalindromeOptimal(string s)
{
    int n = s.size();
    int low = 0, high = 0, start = 0, maxlen = 1;
    for (int i = 0; i < n; i++)
    {
        // odd length
        low = i;
        high = i;
        while (low >= 0 && high < n && s[low] == s[high])
        {
            if (maxlen < high - low + 1)
            {
                start = low;
                maxlen = high - low + 1;
            }
            low--;
            high++;
        }

        // even length
        low = i;
        high = i + 1;
        while (low >= 0 && high < n && s[low] == s[high])
        {
            if (maxlen < high - low + 1)
            {
                start = low;
                maxlen = high - low + 1;
            }
            low--;
            high++;
        }
    }
    return s.substr(start, maxlen);
}
int main()
{
    string s = "babad";
    cout << longestPalindromeOptimal(s);
    return 0;
}