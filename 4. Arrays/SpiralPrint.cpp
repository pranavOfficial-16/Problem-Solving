#include <bits/stdc++.h>
using namespace std;
vector<int> spiralOrder(vector<vector<int>>& matrix) {

   int n = matrix.size();
   int m = matrix[0].size();

   int count = 0;
   int total = n * m;
   vector<int> ans;

   int startingRow = 0;
   int startingCol = 0;
   int endingRow = n - 1;
   int endingCol = m - 1;

   while (startingRow <= endingRow && startingCol <= endingCol) {

      // starting row
      for (int index = startingCol; index <= endingCol; index++)
         ans.push_back(matrix[startingRow][index]);
      startingRow++;

      // ending column
      for (int index = startingRow; index <= endingRow; index++)
         ans.push_back(matrix[index][endingCol]);
      endingCol--;

      // ending row
      if (startingRow <= endingRow) {
         for (int index = endingCol; index >= startingCol; index--)
            ans.push_back(matrix[endingRow][index]);
         endingRow--;
      }

      // starting column
      if (startingCol <= endingCol) {
         for (int index = endingRow; index >= startingRow; index--)
            ans.push_back(matrix[index][startingCol]);
         startingCol++;
      }
   }
   return ans;
}