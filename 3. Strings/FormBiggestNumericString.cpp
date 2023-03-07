#include <bits/stdc++.h>
using namespace std;
int main()
{
    string s = "498732424546";
    sort(s.begin(), s.end(), greater<int>());
    cout << s;
    return 0;
}
