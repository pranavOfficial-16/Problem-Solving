// character patterns

/*
    A
    BB
    CCC
    DDDD
    EEEEE
*/
// #include <iostream>
// using namespace std;
// int main()
// {
//     int n;
//     cin >> n;
//     for (int i = 1; i <= n; i++)
//     {
//         for (int j = 1; j <= i; j++)
//         {
//             char ch = 'A' + i - 1;
//             cout << ch;
//         }
//         cout << endl;
//     }
// }

/*
    A
    BC
    CDE
    DEFG
    EFGHI
*/
// #include <iostream>
// using namespace std;
// int main()
// {
//     int n;
//     cin >> n;
//     for (int i = 1; i <= n; i++)
//     {
//         for (int j = i; j < i + i; j++)
//         {
//             char ch = 'A' + j - 1;
//             cout << ch;
//         }
//         cout << endl;
//     }
// }

/*
    E
    DE
    CDE
    BCDE
    ABCDE
*/
// #include <iostream>
// using namespace std;
// int main()
// {
//     int n;
//     cin >> n;
//     for (int i = n; i >= 1; i--)
//     {
//         for (int j = i; j <= n; j++)
//         {
//             char ch = 'A' + j - 1;
//             cout << ch;
//         }
//         cout << endl;
//     }
//     return 0;
// }

// pattern questions

/*
    1
    22
    333
    4444
    55555
*/
// #include<iostream>
// using namespace std;
// int main(){
// 	int n;
//     cin>>n;
//     for(int i=1;i<=n;i++){
//         for(int j=i;j<(i+i);j++){
//             cout<<i;
//         }
//         cout<<endl;
//     }
// }

/*
    1
    21
    321
    4321
    54321
*/
// #include<iostream>
// using namespace std;
// int main()
// {
//     int n;
//     cin>>n;
//     for(int i=1;i<=n;i++){
//         for(int j=i;j>=1;j--){
//             cout<<j;
//         }
//         cout<<endl;
//     }
//     return 0;
// }

/*
        1
       12
      123
     1234
    12345
*/
// #include <iostream>
// using namespace std;
// int main()
// {
//     int n;
//     cin >> n;
//     for (int i = 1; i <= n; i++)
//     {
//         for (int j = 1; j <= n - i; j++)
//         {
//             cout << " ";
//         }
//         for (int j = 1; j <= i; j++)
//         {
//             cout << j;
//         }
//         cout << endl;
//     }
//     return 0;
// }

// triangle of nos
/*
            1
           232
          34543
         4567654
        567898765
*/
// #include <iostream>
// using namespace std;
// int main()
// {
//     int n, count = 0, count1 = 0, k = 0;
//     cin >> n;
//     for (int i = 1; i <= n; i++)
//     {
//         for (int j = 1; j <= n - i; j++)
//         {
//             cout << " ";
//             count++;
//         }
//         while (k != 2 * i - 1)
//         {
//             if (count <= n - 1)
//             {
//                 cout << i + k;
//                 count++;
//             }
//             else
//             {
//                 count1++;
//                 cout << i + k - 2 * count1;
//             }
//             k++;
//         }
//         count1 = count = k = 0;
//         cout << endl;
//     }
//     return 0;
// }

// Table pattern
/*
        1
        11
        121
        1221
*/
#include <bits/stdc++.h>
using namespace std;
/*
// using 2d vector
vector<vector<int>> numberPattern(int n)
{
    vector<vector<int>> result;
    result.resize(n);
    for (int i = 0; i < n; i++)
    {
        result[i].resize(i + 1);
        for (int j = 0; j <= i; j++)
        {
            if (j == 0 || j == i)
            {
                result[i][j] = 1;
            }
            else
            {
                result[i][j] = 2;
            }
        }
    }
    return result;
}

*/
void numberpattern(int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            if (j == 0 || j == i)
                cout << "1";
            else
                cout << "2";
        }
        cout << endl;
    }
}
int main()
{
    int n;
    cin >> n;
    numberpattern(n);
    return 0;
}