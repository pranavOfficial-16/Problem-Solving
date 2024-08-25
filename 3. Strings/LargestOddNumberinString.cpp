#include <bits/stdc++.h>
using namespace std;
string largestOddNumber(string s)
{
    int end = s.size() - 1;
    while (end >= 0)
    {
        int digit = int(s[end] - '0');
        if (digit % 2 == 1)
            return s.substr(0, end + 1);
        end--;
    }
    return "";
}