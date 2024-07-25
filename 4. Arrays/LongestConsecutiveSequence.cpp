#include <bits/stdc++.h>
using namespace std;
int longestConsecutive(vector<int>& nums) {
   int n = nums.size();

   if (n == 0) return 0;

   int longest = 1;
   unordered_set<int> st;

   for (int i = 0; i < n; i++) {
      st.insert(nums[i]);
   }

   for (auto it : st) {
      // if it is not in the set
      if (st.find(it - 1) == st.end()) {
         int count = 1;
         int curr = it;
         // if it is in the set
         while (st.find(curr + 1) != st.end()) {
            curr++;
            count++;
         }
         longest = max(longest, count);
      }
   }
   return longest;
}