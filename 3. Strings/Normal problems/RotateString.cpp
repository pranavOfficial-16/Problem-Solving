#include <bits/stdc++.h>
using namespace std;
bool rotateString(string s, string goal)
{

    int n = s.size();
    string temp;
    for (int i = 0; i < n; i++)
    {
        temp = s;
        for (int j = 0; j < n; j++)
            temp[(i + j) % n] = s[j];
        
        if (temp == goal)
            return true;
    }
    return false;
}