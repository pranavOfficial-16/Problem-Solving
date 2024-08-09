// #include <iostream>
// using namespace std;
// int main()
// {
//     long n, digit, i = 0;
//     cin >> n;
//     long a[50];
//     while (n != 0)
//     {
//         digit = n % 2;
//         a[i] = digit;
//         n = n / 2;
//         i++;
//     }
//     for (long j = i - 1; j >= 0; j--)
//     {
//         cout << a[j];
//     }
//     return 0;
// }

#include <iostream>
#include <math.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  int ans = 0, i = 0;
  while (n != 0) {
    int bit = n & 1;
    ans += (bit * pow(10, i));
    n = n >> 1;
    i++;
  }
  cout<<ans;
}