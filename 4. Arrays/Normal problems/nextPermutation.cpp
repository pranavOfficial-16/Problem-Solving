#include <bits/stdc++.h>
using namespace std;
void rev(vector<int>& nums, int start, int end) {
   while (start < end) {
      int temp = nums[start];
      nums[start] = nums[end];
      nums[end] = temp;
      start++;
      end--;
   }
}
void nextPermutation(vector<int>& nums) {
   int index = -1;
   for (int i = nums.size() - 2; i >= 0; i--) {
      if (nums[i] < nums[i + 1]) {
         index = i;
         break;
      }
   }
   if (index == -1)
      rev(nums, 0, nums.size() - 1);
   else {
      for (int i = nums.size() - 1; i >= index; i--) {
         if (nums[i] > nums[index]) {
            swap(nums[i], nums[index]);
            break;
         }
      }
      rev(nums, index + 1, nums.size() - 1);
   }
}