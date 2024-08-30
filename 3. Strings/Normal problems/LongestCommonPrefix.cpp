#include <bits/stdc++.h>
using namespace std;
string longestCommonPrefix(vector<string> &strs)
{
    string firstword = strs[0], ans = "";
    for (int i = 0; i < firstword.size(); i++)
    {
        int row = 1;
        while (row < strs.size())
        {
            if (firstword[i] != strs[row][i])
                return ans;
            row++;
        }
        if (row == strs.size())
            ans += firstword[i];
    }
    return ans;
}
int main()
{
    vector<string> arr{"graceful", "grace", "disgraceful", "gracefully"};
    cout << longestCommonPrefix(arr) << endl;
}