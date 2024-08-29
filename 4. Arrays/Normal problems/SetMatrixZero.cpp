#include <bits/stdc++.h>
using namespace std;
void setZeroes(vector<vector<int>>& matrix) {
   int m = matrix.size();
   int n = matrix[0].size();
   vector<vector<int>> temp(m, vector<int>(n, 0));
   set<int> set_row, set_col;
   for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
         if (matrix[i][j] == 0) {
            set_row.insert(i);
            set_col.insert(j);
         }
      }
   }
   for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
         if (set_row.find(i) == set_row.end() &&
             set_col.find(j) == set_col.end()) {
            temp[i][j] = matrix[i][j];
         }
      }
   }
   matrix = temp;
}