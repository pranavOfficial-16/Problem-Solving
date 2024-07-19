// C++ program to find GCD of two numbers

// Method-1 - normal approach
// Time complexity - o(min(a,b)),space complexity - o(1)

// #include <bits/stdc++.h>
// using namespace std;
// int gcd(int a, int b)
// {
//     int result = min(a, b);
//     while (result > 0)
//     {
//         if (a % result == 0 && b % result == 0)
//             break;
//         result--;
//     }
//     return result;
// }
// int main()
// {
//     int a = 98, b = 56;
//     cout << gcd(a, b);
//     return 0;
// }

// Method-2 - using recursion
// Time complexity - o(log(min(a,b))),space complexity - o(log(min(a,b)))
#include <bits/stdc++.h>
using namespace std;
int gcd(int a, int b) {
   if (a == 0) {
      return b;
   }
   return gcd(b % a, a);
}
int main() {
   int a = 98, b = 56;
   cout << gcd(a, b);
   return 0;
}
