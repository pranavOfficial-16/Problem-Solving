#include <bits/stdc++.h>
using namespace std;
void rotate(vector<vector<int>>& matrix) {
   int n = matrix.size();
   vector<vector<int>> temp(n, vector<int>(n));
   for (int i = 0; i < n; i++) {
      int next = 0;
      for (int j = n - 1; j >= 0; j--) {
         temp[i][next++] = matrix[j][i];
      }
   }
   matrix = temp;
}