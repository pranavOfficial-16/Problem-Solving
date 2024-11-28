#include <bits/stdc++.h>
using namespace std;
string convert2binary(int n)
{
    string ans;
    while (n != 0)
    {
        n % 2 == 1 ? ans += '1' : ans += '0';
        n = n / 2;
    }
    int start = 0, end = ans.size() - 1;
    char temp;
    while (start < end)
    {
        temp = ans[start];
        ans[start] = ans[end];
        ans[end] = temp;
        start++;
        end--;
    }
    return ans;
}
int main()
{
    int n;
    cin >> n;
    cout << convert2binary(n) << endl;
}