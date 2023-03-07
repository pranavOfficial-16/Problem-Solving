// questions based on bits,bitwise operator etc.

// To get bit
//  #include<iostream>
//  using namespace std;
//  int getbit(int n,int pos){
//      return (n & (1<<pos)!=0);
//  }
//  int main()
//  {
//      cout<<getbit(5,2)<<endl;
//      return 0;
//  }

// To set bit
//  #include<iostream>
//  using namespace std;
//  int setbit(int n,int pos){
//      return (n | (1<<pos));
//  }
//  int main()
//  {
//      cout<<setbit(5,1)<<endl;
//      return 0;
//  }

// To clear bit
// #include <iostream>
// using namespace std;
// int clearBit(int n, int pos)
// {
//     int mask = ~(1 << pos);
//     return (n & mask);
// }
// int main()
// {
//     cout<<clearBit(5,2)<<endl;
//     return 0;
// }

// To update bit
//  #include<iostream>
//  using namespace std;
//  int updateBit(int n,int pos,int value){
//      int mask = ~(1<<pos);
//      n = n & mask;
//      return (n | (value<<pos));
//  }
//  int main()
//  {
//      cout<<updateBit(5,1,1)<<endl;
//      return 0;
//  }

// check if a given no is power of 2 using bits
//  #include<iostream>
//  using namespace std;
//  int ispowerof2(int n){
//      return (n && !(n & n-1));
//  }
//  int main()
//  {
//      cout<<ispowerof2(14)<<endl;
//      return 0;
//  }

// count the no of ones in binary represetation of a number
// #include<iostream>
// using namespace std;
// int numberofones(int n){
//     int count = 0;
//     while(n){
//         n = n & n-1;
//         count++;
//     }
//     return count;
// }
// int main()
// {
//     cout<<numberofones(19)<<endl;
//     return 0;
// }

// generate all the possible subsets of a set
//  #include<iostream>
//  using namespace std;
//  void subsets(int arr[],int n){
//      for(int i=0;i<(1<<n);i++){
//          for(int j=0;j<n;j++){
//              if( i & (1<<j)){
//                  cout<<arr[j]<<" ";
//              }
//          }
//          cout<<endl;
//      }
//  }
//  int main()
//  {
//      int arr[4] = {1,2,3,4};
//      subsets(arr,4);
//      return 0;
//  }

// finding unique no in an array i.e. present only once
// using xor operator
//  #include<iostream>
//  using namespace std;
//  int unique(int arr[],int n){
//      int xorsum = 0;
//      for(int i=0;i<n;i++){
//          xorsum=xorsum^arr[i];
//      }
//      return xorsum;
//  }
//  int main()
//  {
//      int arr[] ={1,2,3,4,1,2,3};
//      cout<<unique(arr,7)<<endl;
//      return 0;
//  }

// find 2 unique nos in an array i.e. 2 nos present only once
// #include <iostream>
// using namespace std;
// int setBit(int n, int pos)
// {
//     return ((n & (1 << pos)) != 0);
// }
// void unique(int arr[], int n)
// {
//     int xorsum = 0;
//     for (int i = 0; i < n; i++)
//     {
//         xorsum = xorsum ^ arr[i];
//     }
//     int tempxor = xorsum;
//     int setbit = 0, pos = 0;
//     while (setbit != 1)
//     {
//         setbit = xorsum & 1;
//         pos++;
//         xorsum = xorsum >> 1;
//     }
//     int newxor = 0;
//     for (int i = 0; i < n; i++)
//     {
//         if (setBit(arr[i],pos-1))
//         {
//             newxor = newxor ^ arr[i];
//         }
//     }
//     cout << newxor << endl;
//     cout << (tempxor ^ newxor) << endl;
// }
// int main()
// {
//     int arr[] = {1, 2, 3, 1, 2, 3, 5, 7};
//     unique(arr, 8);
//     return 0;
// }

// finding unique no in an array i.e. present only once while rest nos are present thrice
// #include <iostream>
// using namespace std;
// bool getBit(int n, int pos)
// {
//     return ((n & (1 << pos)) != 0);
// }
// int setBit(int n, int pos)
// {
//     return (n | (1 << pos));
// }
// int unique(int arr[], int n)
// {
//     int result = 0;
//     for (int i = 0; i < 64; i++)
//     {
//         int sum = 0;
//         for (int j = 0; j < n; j++)
//         {
//             if (getBit(arr[j], i))
//             {
//                 sum++;
//             }
//         }
//         if (sum % 3 != 0)
//         {
//             result = setBit(result, i);
//         }
//     }
//     return result;
// }
// int main()
// {
//     int arr[] = {1, 2, 3, 4, 1, 2, 3, 1, 2, 3};
//     cout << unique(arr, 10) << endl;
//     return 0;
// }

#include<iostream>
using namespace std;
int main()
{
    int a = 97<<1;
    cout<<a;
    return 0;
}