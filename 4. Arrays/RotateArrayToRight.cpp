// Optimal approach - reversal algorithm
#include <bits/stdc++.h>
using namespace std;
void rev(int *a, int start, int end) {
   while (start < end) {
      int temp = a[start];
      a[start] = a[end];
      a[end] = temp;
      start++;
      end--;
   }
}
// method 1
void rotate(int *a, int d, int n) {
   // if d>n
   d = d % n;
   rev(a, 0, n - 1);
   rev(a, d, n - 1);
   rev(a, 0, d - 1);
}
// method 2
void rotate1(int *a, int d, int n) {
   int *temp = new int[n];
   for(int i=0;i<n;i++){
      temp[(i + d) % n] = a[i];
   }
   for (int i = 0; i < n; i++) {
      a[i] = temp[i];
   }
}
int main() {
   int n;
   cin >> n;
   int *a = new int[n];
   for (int i = 0; i < n; i++) {
      cin >> a[i];
   }
   int d;
   cin >> d;
   rotate1(a, d, n);
   for (int i = 0; i < n; i++) {
      cout << a[i] << " ";
   }
   return 0;
}