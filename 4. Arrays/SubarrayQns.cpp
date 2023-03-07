// Subarray - continuous part of the array
// no of subarrays of array with n elements - nc2+n = n(n+1)/2

// sum of all sub arrays
//  #include <iostream>
//  using namespace std;
//  int main()
//  {
//      int n, sum;
//      cin >> n;
//      int a[n];
//      for (int i = 0; i < n; i++)
//      {
//          cin >> a[i];
//      }
//      for (int i = 0; i < n; i++)
//      {
//          sum = 0;
//          for (int j = i; j < n; j++)
//          {
//              sum += a[j];
//              cout << sum << endl;
//          }
//      }
//      return 0;
//  }

// longest arithmetic subarray(google kickstart)
// arithmetic subarray - array with atleast 2
//                       integers and diff are equal
// #include <iostream>
// using namespace std;
// int main()
// {
//     int n;
//     cin>>n;
//     int a[n];
//     for(int i = 0; i < n; i++)
//     {
//         cin >> a[i];
//     }
//     int maxsubarrlength = 2; // max length of subarray
//     int count = 2;           // length of subarray
//     int prev = a[1] - a[0];  // to hold the previous common diff
//     for (int i = 2; i < n; i++)
//     {
//         if (prev == a[i] - a[i - 1])
//         {
//             count++;
//         }
//         else
//         {
//             prev = a[i] - a[i - 1];
//             count = 2;
//         }
//         maxsubarrlength = max(maxsubarrlength, count);
//     }
//     cout << "longest arithmetic subarray length : " << maxsubarrlength;
//     return 0;
// }

// record breaking day count(google kickstart)
//  #include <iostream>
//  #include <climits>
//  using namespace std;
//  int main()
//  {
//      int n;
//      cin >> n;
//      int a[n + 1];
//      a[n] = -1;
//      for (int i = 0; i < n; i++)
//      {
//          cin >> a[i];
//      }
//      if (n == 1)
//      {
//          cout << "1" << endl;
//          return 0;
//      }
//      int count = 0;
//      int mx = INT_MIN;
//      for(int i=0;i<n;i++){
//          if(a[i]>mx && a[i]>a[i+1]){
//              count++;
//          }
//          mx=max(mx,a[i]);
//      }
//      cout<<count<<endl;
//      return 0;
//  }

// Subarray with given sum
// #include <iostream>
// using namespace std;
// int main()
// {
//     int n, sum;
//     cin >> n;
//     int a[n];
//     int s;
//     cin >> s;
//     for (int i = 0; i < n; i++)
//     {
//         cin >> a[i];
//     }
//     int flag = 0;
//     int temp[10], k;
//     int start, end;
//     for (int i = 0; i < n; i++)
//     {
//         sum = 0;
//         k = 0;
//         for (int j = i; j < n; j++)
//         {
//             sum += a[j];
//             temp[k++] = j + 1;
//             if (sum == s)
//             {
//                 cout << temp[0] << " " << temp[k - 1];
//                 flag = 1;
//                 break;
//             }
//         }
//         if (flag == 1)
//             break;
//     }
//     return 0;
// }

// print all the possible subarrays
//   #include<iostream>
//   using namespace std;
//   int main()
//   {
//       int n;
//       cin>>n;
//       int a[n];
//       for(int i=0;i<n;i++){
//           cin>>a[i];
//       }
//       for(int i=0;i<n;i++){
//           for(int j=i;j<n;j++){
//               for(int k=i;k<=j;k++){
//                   cout<<a[k]<<" ";
//               }
//               cout<<endl;
//           }
//           cout<<endl;
//       }
//       return 0;
//   }

// print the subarray which has max sum
//  #include <iostream>
//  #include <climits>
//  using namespace std;
//  int main()
//  {
//      int n, mx = INT_MIN, sum;
//      cin >> n;
//      int a[n];
//      for (int i = 0; i < n; i++)
//      {
//          cin >> a[i];
//      }
//      for (int i = 0; i < n; i++)
//      {
//          for (int j = i; j < n; j++)
//          {
//              sum = 0;
//              for (int k = i; k <= j; k++)
//              {
//                 sum += a[k];
//              }
//              mx = max(mx, sum);
//          }
//      }
//      cout << mx << endl;
//      return 0;
//  }

// print the subarray which has max sum using 2 loops
// #include <iostream>
// #include <climits>
// using namespace std;
// int main()
// {
//     int n, mx = INT_MIN, sum;
//     cin >> n;
//     int a[n];
//     for (int i = 0; i < n; i++)
//     {
//         cin >> a[i];
//     }
//     for (int i = 0; i < n; i++)
//     {
//         sum = 0;
//         for (int j = i; j < n; j++)
//         {
//             sum += a[j];
//             mx = max(mx, sum);
//         }
//     }
//     cout << mx << endl;
//     return 0;
// }

// print the subarray which has max sum using Kadane's algorithm
// #include <iostream>
// #include <climits>
// using namespace std;
// int main()
// {
//     int n, mx = INT_MIN;
//     cin >> n;
//     int a[n];
//     for (int i = 0; i < n; i++)
//     {
//         cin >> a[i];
//     }
//     int sum = 0;
//     for (int i = 0; i < n; i++)
//     {
//         sum += a[i];
//         if (sum < 0)
//             sum = 0;
//         mx = max(mx, sum);
//     }
//     cout << mx << endl;
//     return 0;
// }

// Maximum of all subarrays of size k
// This approach works but gives time exceeded error
// Time complexcity - 0(n)
// vector<int> max_of_subarrays(int *a, int n, int k)
// {
//     vector<int> v;
//     if (n == 1)
//     {
//         v.push_back(a[0]);
//         return v;
//     }
//     int count = 0, mx = INT_MIN, j = 0;
//     for (int i = 0; i < n; i++)
//     {
//         if (mx < a[i])
//             mx = a[i];
//         count++;
//         if (count == k)
//         {
//             v.push_back(mx);
//             mx = INT_MIN;
//             count = 0;
//             i = j;
//             j++;
//         }
//     }
//     return v;
// }
