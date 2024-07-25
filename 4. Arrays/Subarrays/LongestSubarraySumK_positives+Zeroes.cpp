#include <bits/stdc++.h>
using namespace std;
// bruteforce
int solve(int arr[], int n, int k) {
   int len = INT_MIN, sum;
   for (int i = 0; i < n; i++) {
      for (int j = i; j < n; j++) {
         sum = 0;
         for (int k = i; k <= j; k++) {
            sum += arr[k];
         }
         if (sum == k) len = max(len, j - i + 1);
      }
   }
   return len;
}

// better
int solve1(int arr[], int n, int k) {
   int len = INT_MIN, sum;
   for (int i = 0; i < n; i++) {
      sum = 0;
      for (int j = i; j < n; j++) {
         sum += arr[j];
         if (sum == k) len = max(len, j - i + 1);
      }
   }
   return len;
}

// optimal
int solve2(int arr[], int n, int k) {
   int left = 0, right = 0;
   int sum = arr[0];
   int maxlen = 0;
   while (right < n) {
      while (sum > k && left <= right) {
         sum -= arr[left];
         left++;
      }

      if (sum == k) maxlen = max(maxlen, right - left + 1);

      right++;
      if (right < n) sum += arr[right];
   }
   return maxlen;
}
int main() {
   int n;
   cin >> n;
   int *arr = new int[n];
   for (int i = 0; i < n; i++) cin >> arr[i];
   int k;
   cin >> k;
   cout << solve2(arr, n, k);
   return 0;
}