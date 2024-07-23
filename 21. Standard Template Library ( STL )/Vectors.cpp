// vectors are inbuild dynamic array
#include <bits/stdc++.h>
using namespace std;
int main() {
   vector<int> v;

   for (int i = 0; i < 10; i++) {
      v.push_back(i);  // inserting elements in the vector
   }

   cout << "the elements in the vector: ";
   for (auto it = v.begin(); it != v.end(); it++) cout << *it << " ";

   cout << "\nThe front element of the vector: " << v.front();
   cout << "\nThe last element of the vector: " << v.back();
   cout << "\nThe size of the vector: " << v.size();
   cout << "\nDeleting element from the end: " << v[v.size() - 1];
   // sort(v.begin(), v.end());
   // reverse(v.begin(), v.end());
   // v.pop_back();

   cout << "\nPrinting the vector after removing the last element:" << endl;
   for (int i = 0; i < v.size(); i++) cout << v[i] << " ";

   cout << "\nInserting 5 at the beginning:" << endl;
   v.insert(v.begin(), 5);
   cout << "The first element is: " << v[0] << endl;
   cout << "Erasing the first element" << endl;
   v.erase(v.begin());
   cout << "Now the first element is: " << v[0] << endl;

   if (v.empty())
      cout << "\nvector is empty";
   else
      cout << "\nvector is not empty" << endl;

   v.clear();
   cout << "Size of the vector after clearing the vector: " << v.size();

   // dynamic
   vector<int> *dynamic = new vector<int>();

   // static
   vector<int> v1;
   v1.push_back(10);
   v1.push_back(20);
   v1.push_back(30);
   v1.emplace_back(40);
   /*
       v[] we use for only get and update (not to insert)
   */
   cout << v1.at(1) << endl;
   for (int i : v1) cout << i << endl;
   for (auto i : v1) cout << i << endl;
   // static creation of vector
   vector<int> v2;
   /*
       dynamic creation of vector
       vector<int> *vp = new vector<int>();
   */
   for (int i = 1; i <= 5; i++) v2.push_back(i);
   cout << "Output of begin and end: ";
   for (auto i = v.begin(); i != v.end(); i++) cout << *i << " ";
   v2.pop_back();
   cout << "\nOutput after pop: ";
   for (auto i = v2.begin(); i != v2.end(); ++i) cout << *i << " ";
   cout << "\nOutput of rbegin and rend: ";
   for (auto ir = v2.rbegin(); ir != v2.rend(); ++ir) cout << *ir << " ";
   cout << "\nOutput of crbegin and crend : ";
   for (auto ir = v2.crbegin(); ir != v2.crend(); ++ir) cout << *ir << " ";
   // 2d vectors
   vector<vector<int>> vect{{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
   // method-1
   for (int i = 0; i < vect.size(); i++) {
      for (int j = 0; j < vect[i].size(); j++) {
         cout << vect[i][j] << " ";
      }
      cout << endl;
   }
   // method-2
   for (vector<int> vect1D : vect) {
      for (int x : vect1D) {
         cout << x << " ";
      }
      cout << endl;
   }
   // for declaring 2d vector
   int n = 3;
   int m = 4;
   vector<vector<int>> vec(n, vector<int>(m));
   for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
         cout << vec[i][j] << " ";
      }
      cout << endl;
   }
   return 0;
}