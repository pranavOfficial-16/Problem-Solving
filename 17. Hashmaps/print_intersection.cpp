#include <bits/stdc++.h>
using namespace std;
void printIntersection(int a1[], int a2[], int n, int m)
{
    unordered_map<int, int> map;
    for (int i = 0; i < m; i++)
        map[a2[i]]++;
    for (int i = 0; i < n; i++)
    {
        if (map[a1[i]] > 0)
        {
            cout << a1[i] << endl;
            map[a1[i]]--;
        }
    }
}