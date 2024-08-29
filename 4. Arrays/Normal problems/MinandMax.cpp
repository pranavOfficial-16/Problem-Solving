#include <bits/stdc++.h>
using namespace std;
int solvemax(int *arr, int n) {
   int maxi = -1;
   for (int i = 0; i < n; i++) {
      if (arr[i] > maxi) {
         maxi = arr[i];
      }
   }
   return maxi;
}
int solvemin(int *arr, int n) {
   int mini = INT_MAX;
   for (int i = 0; i < n; i++) {
      if (arr[i] < mini) {
         mini = arr[i];
      }
   }
   return mini;
}
int main() {
   int n;
   cin >> n;
   int *arr = new int[n];
   for (int i = 0; i < n; i++) {
      cin >> arr[i];
   }
   cout << solvemax(arr, n) << endl;
   cout << solvemin(arr, n);
   return 0;
}