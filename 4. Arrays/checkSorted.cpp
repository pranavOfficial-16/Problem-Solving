#include <bits/stdc++.h>
using namespace std;
bool arraySortedOrNot(int arr[], int n) {
   if (n == 0 || n == 1) {
      return true;
   }
   for (int i = 1; i < n; i++)
      if (arr[i - 1] > arr[i]) {
         return false;
      }
   return true;
}
int main() {
   int n;
   cin >> n;
   int *a = new int[n];
   for (int i = 0; i < n; i++) {
      cin >> a[i];
   }
   cout << arraySortedOrNot(a, n);
   return 0;
}