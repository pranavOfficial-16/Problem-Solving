#include <bits/stdc++.h>
using namespace std;
// method 1 - using set
vector<int> findUnion(int arr1[], int arr2[], int n, int m) {
   map<int, int> mp;
   for (int i = 0; i < n; i++) mp[arr1[i]]++;
   for (int i = 0; i < m; i++) mp[arr2[i]]++;
   vector<int> v;
   for (auto i : mp) v.push_back(i.first);
   return v;
}
// method 2 - using Two Pointers
vector<int> FindUnion(int arr1[], int arr2[], int n, int m) {
   int i = 0, j = 0;
   vector<int> Union;
   while (i < n && j < m) {
      if (arr1[i] <= arr2[j]) {
         if (Union.size() == 0 || Union.back() != arr1[i])
            Union.push_back(arr1[i]);
         i++;
      } else {
         if (Union.size() == 0 || Union.back() != arr2[j])
            Union.push_back(arr2[j]);
         j++;
      }
   }
   while (i < n) {
      if (Union.back() != arr1[i]) Union.push_back(arr1[i]);
      i++;
   }
   while (j < m) {
      if (Union.back() != arr2[j]) Union.push_back(arr2[j]);
      j++;
   }
   return Union;
}
int main() {
   int n, m;
   cin >> n >> m;
   int *arr1 = new int[n];
   int *arr2 = new int[m];
   for (int i = 0; i < n; i++) cin >> arr1[i];
   for (int i = 0; i < m; i++) cin >> arr2[i];
   vector<int> ans = findUnion(arr1, arr2, n, m);
   for (int i : ans) cout << i << ' ';
   return 0;
}