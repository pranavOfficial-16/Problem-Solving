#include <bits/stdc++.h>
using namespace std;
vector<int> findUnion(int arr1[], int arr2[], int n, int m)
{
    map<int, int> mp;
    for (int i = 0; i < n; i++)
        mp[arr1[i]]++;
    for (int i = 0; i < m; i++)
        mp[arr2[i]]++;
    vector<int> v;
    for (auto i : mp)
        v.push_back(i.first);
    return v;
}
int main()
{
    int n, m;
    cin >> n >> m;
    int *arr1 = new int[n];
    int *arr2 = new int[m];
    for (int i = 0; i < n; i++)
        cin >> arr1[i];
    for (int i = 0; i < m; i++)
        cin >> arr2[i];
    vector<int> ans = findUnion(arr1, arr2, n, m);
    for (int i : ans)
        cout << i << ' ';
    return 0;
}