#include <bits/stdc++.h>
using namespace std;
vector<int> twoSum(vector<int>& nums, int target) {
   int i = 0, j = 1, n = nums.size();
   vector<int> ans;
   while (i < n) {
      if (nums[i] + nums[j] == target) {
         ans.push_back(i);
         ans.push_back(j);
         return ans;
      }
      j++;
      if (j == n) {
         i++;
         j = i + 1;
      }
   }
   return ans;
}