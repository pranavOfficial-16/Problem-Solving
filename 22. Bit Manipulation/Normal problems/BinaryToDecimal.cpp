#include <bits/stdc++.h>
using namespace std;
int convert2decimal(string ans)
{
    int len = ans.size() - 1;
    int p2 = 1, num = 0;
    for (int i = len; i >= 0; i--)
    {
        if (ans[i] == '1')
            num = num + p2;
        p2 = p2 * 2;
    }
    return num;
}
int main()
{
    string ans;
    cin >> ans;
    cout << convert2decimal(ans);
}