#include <bits/stdc++.h>
using namespace std;

// bruteforce
int editDistance(string s1, string s2)
{
    // base case
    if (s1.size() == 0 || s2.size() == 0)
        return max(s1.size(), s2.size());

    if (s1[0] == s2[0])
        return editDistance(s1.substr(1), s2.substr(1));
    else
    {
        int x = 1 + editDistance(s1.substr(1), s2);           // insert
        int y = 1 + editDistance(s1, s2.substr(1));           // delete
        int z = 1 + editDistance(s1.substr(1), s2.substr(1)); // replace
        return min(x, min(y, z));
    }
}

// memoization
int editDistance_mem(string s, string t, int **output)
{
    int m = s.size();
    int n = t.size();

    if (s.size() == 0 || t.size() == 0)
        return max(s.size(), t.size());

    // Check if ans already exists
    if (output[m][n] != -1)
        return output[m][n];

    int ans;
    if (s[0] == t[0])
        ans = editDistance_mem(s.substr(1), t.substr(1), output);
    else
    {
        // Insert
        int x = editDistance_mem(s.substr(1), t, output) + 1;
        // Delete
        int y = editDistance_mem(s, t.substr(1), output) + 1;
        // Replace
        int z = editDistance_mem(s.substr(1), t.substr(1), output) + 1;
        ans = min(x, min(y, z));
    }

    // Save the ans
    output[m][n] = ans;

    // Return the ans
    return ans;
}
int editDistance_mem(string s, string t)
{
    int m = s.size();
    int n = t.size();
    int **ans = new int *[m + 1];
    for (int i = 0; i <= m; i++)
    {
        ans[i] = new int[n + 1];
        for (int j = 0; j <= n; j++)
        {
            ans[i][j] = -1;
        }
    }
    return editDistance_mem(s, t, ans);
}

// dp
int editDistance_DP(string s, string t)
{
    int m = s.size();
    int n = t.size();
    int **output = new int *[m + 1];
    for (int i = 0; i <= m; i++)
    {
        output[i] = new int[n + 1];
    }

    // Fill 1st row
    for (int j = 0; j <= n; j++)
    {
        output[0][j] = j;
    }

    // Fill 1st col
    for (int i = 1; i <= m; i++)
    {
        output[i][0] = i;
    }

    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (s[m - i] == t[n - j])
            {
                output[i][j] = output[i - 1][j - 1];
            }
            else
            {
                int a = output[i - 1][j];
                int b = output[i][j - 1];
                int c = output[i - 1][j - 1];
                output[i][j] = min(a, min(b, c)) + 1;
            }
        }
    }

    return output[m][n];
}
int main()
{
    string s1, s2;
    cin >> s1 >> s2;
    cout << editDistance(s1, s2) << endl;
    return 0;
}