#include <bits/stdc++.h>
using namespace std;
bool checkPallindrome(string s) {
   int n = s.size();
   for (int i = 0; i < n; i++) {
      if (s[i] != s[n - i - 1]) return false;
   }
   return true;
}
int main() {
   string s = "12121";
   checkPallindrome(s) ? cout << "true" : cout << "false";
   return 0;
}