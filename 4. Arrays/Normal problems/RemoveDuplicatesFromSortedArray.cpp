#include <bits/stdc++.h>
using namespace std;
int removeDuplicates(vector<int>& nums) {
   int index = 0;
   for (int j = 1; j < nums.size(); j++) {
      if (nums[j] != nums[index]) {
         nums[index + 1] = nums[j];
         index++;
      }
   }
   return index + 1;
}
int main() {
   int n;
   cin >> n;
   vector<int> v(n);
   for (int i = 0; i < n; i++) {
      cin >> v[i];
   }
   cout << removeDuplicates(v) << endl;
   return 0;
}
