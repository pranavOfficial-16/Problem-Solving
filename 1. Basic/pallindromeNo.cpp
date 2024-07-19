#include <bits/stdc++.h>
using namespace std;
bool isPalindrome(int x) {

   if (x < 0) return false;

   long long num = x, rev = 0;
   while (x) {
      rev = (rev * 10) + (x % 10);
      x /= 10;
   }
   return num == rev;
}
int main() {
   int x;
   cin >> x;
   cout << isPalindrome(x);
   return 0;
}