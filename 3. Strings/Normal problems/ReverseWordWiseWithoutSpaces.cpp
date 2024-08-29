#include <bits/stdc++.h>
using namespace std;
void rev(string &s, int start, int end)
{
    while (start < end)
    {
        char temp = s[start];
        s[start] = s[end];
        s[end] = temp;
        start++;
        end--;
    }
}
string reverseWords(string s)
{
    int n = s.size();
    rev(s, 0, n - 1); // reverse whole sentence
    int i = 0, left = 0, right = 0;
    while (i < n)
    {
        while (i < n && s[i] == ' ')
            i++;
        if (i == n)
            break;
        while (i < n && s[i] != ' ')
            s[right++] = s[i++];
        rev(s, left, right - 1); // reverse word wise
        s[right++] = ' ';
        left = right;
        i++;
    }
    s.resize(right - 1);
    return s;
}