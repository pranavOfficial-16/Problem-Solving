// No is prime or Non-prime
// #include <iostream>
// #include <math.h>
// using namespace std;
// string checkprime(int n)
// {
//     if(n==1)
//         return "Non-prime";
//     for (int i = 2; i <= sqrt(n); i++)
//     {
//         if (n % i == 0)
//             return "Non-prime";
//     }
//     return "Prime";
// }
// int main()
// {
//     int n, i;
//     cin >> n;
//     cout<<checkprime(n);
//     return 0;
// }

// prime nos between a and b
// #include<iostream>
// #include <math.h>
// using namespace std;
// int main()
// {
//     int num, a, b;
//     cin >> a >> b;
//     for (int num = a; num <= b; num++)
//     {
//         int i;
//         for (i = 2; i < num; i++)
//         {
//             if (num % i == 0)
//                 break;
//         }
//         if (i == num)
//             cout << i << endl;
//     }
//     return 0;
//  }

// sieve of eratosthenes
// Time Complexity: O(n*log(log(n)))
// #include <iostream>
// using namespace std;
// void primeSieve(int n)
// {
//     int prime[100] = {0};
//     for (int i = 2; i <= n; i++)
//     {
//         if (prime[i] == 0)
//         {
//             for (int j = i * i; j <= n; j += i)
//             {
//                 prime[j] = 1;
//             }
//         }
//     }
//     for (int i = 2; i <= n; i++)
//     {
//         if (prime[i] == 0)
//         {
//             cout << i << " ";
//         }
//     }
// }
// int main()
// {
//     int n;
//     cin >> n;
//     primeSieve(n);
//     return 0;
// }

// prime factorization using sieve of eratosthenes
#include <iostream>
using namespace std;
void primefactor(int n)
{
    int spf[100] = {0};
    for (int i = 2; i <= n; i++)
    {
        spf[i] = i;
    }
    for (int i = 2; i <= n; i++)
    {
        if (spf[i] == i)
        {
            for (int j = i * i; j <= n; j += i)
            {
                if (spf[j] == j)
                {
                    spf[j] = i;
                }
            }
        }
    }
    while (n != 1)
    {
        cout << spf[n] << " ";
        n = n / spf[n];
    }
}
int main()
{
    int n;
    cin >> n;
    primefactor(n);
    return 0;
}