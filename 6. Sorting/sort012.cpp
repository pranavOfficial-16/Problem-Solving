// sort an array containing twos and zeros and ones
#include <bits/stdc++.h>
using namespace std;
// method 1
void sortColors(vector<int> &nums)
{
   int cntZeros = 0, cntOnes = 0, cntTwos = 0;
   for (int i = 0; i < nums.size(); i++)
   {
      if (nums[i] == 0)
         cntZeros++;
      else if (nums[i] == 1)
         cntOnes++;
      else if (nums[i] == 2)
         cntTwos++;
   }
   nums.clear();
   for (int i = 0; i < cntZeros; i++)
      nums.push_back(0);
   for (int i = 0; i < cntOnes; i++)
      nums.push_back(1);
   for (int i = 0; i < cntTwos; i++)
      nums.push_back(2);
}
// method 2
void sort012(int *a, int n)
{
   int temp[n];
   for (int i = 0; i < n; i++)
      temp[i] = a[i];
   int j = 0, k = n - 1, twos = 0;
   for (int i = 0; i < n; i++)
   {
      if (temp[i] == 0)
         a[j++] = 0;
      else if (temp[i] == 1)
         a[k--] = 1;
      else
      {
         a[k--] = 1;
         twos++;
      }
   }
   for (int i = n - twos; i < n; i++)
      a[i] = 2;
}
int main()
{
   int n;
   cin >> n;
   int a[n];
   for (int i = 0; i < n; i++)
      cin >> a[i];
   sort012(a, n);
   for (int i = 0; i < n; i++)
      cout << a[i] << " ";
   return 0;
}