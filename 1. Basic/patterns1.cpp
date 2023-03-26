/*
 * * * *
 * * * *
 * * * *
 * * * *
 * * * *
 */
// #include<iostream>
// using namespace std;
// int main()
// {
//     int row,col;
//     cin>>row>>col;
//     for(int i=1;i<=row;i++){
//         for(int j=1;j<=col;j++){
//             cout<<"* ";
//         }
//         cout<<endl;
//     }
//      return 0;
// }

/*
 * * * *
 *     *
 *     *
 *     *
 * * * *
 */
// #include<iostream>
// using namespace std;
// int main()
// {
//     int row,col;
//     cin>>row>>col;
//     for(int i=1;i<=row;i++){
//         for(int j=1;j<=col;j++){
//             if(i==1 || i==row || j==1 || j==col){
//                 cout<<"*";
//             }
//             else
//             cout<<" ";
//         }
//         cout<<endl;
//     }
//     return 0;
// }

/*
    Inverted half pyramid
    *****
    ****
    ***
    **
    *
*/
// #include<iostream>
// using namespace std;
// int main()
// {
//     int row;
//     cin>>row;
//     for(int i=row;i>=1;i--){
//         for(int j=1;j<=i;j++){
//             cout<<"*";
//         }
//         cout<<endl;
//     }
//     return 0;
// }

/*
    Inverted half pyramid after 180 rotation
              *
            * *
          * * *
        * * * *
      * * * * *
    * * * * * *
*/
// #include<iostream>
// using namespace std;
// int main()
// {
//     int row;
//     cin>>row;
//     for(int i=1;i<=row;i++){
//         for(int j=1;j<=row;j++){
//             if(j<=row-i)
//             cout<<"  ";
//             else
//             cout<<"* ";
//         }
//         cout<<endl;
//     }
//     return 0;
// }

/*
    Half pyramid using nos
    1
    1 2
    1 2 3
    1 2 3 4
*/
// #include<iostream>
// using namespace std;
// int main()
// {
//     int row;
//     cin>>row;
//     for(int i=1;i<=row;i++){
//         for(int j=1;j<=i;j++){
//             cout<<j<<" ";
//         }
//         cout<<endl;
//     }
//     return 0;
// }

/*
    floyd's triangle
    1
    2 3
    4 5 6
    7 8 9 10
    11 12 13 14 15

*/
// #include<iostream>
// using namespace std;
// int main()
// {
//     int row,count=1;
//     cin>>row;
//     for(int i=1;i<=row;i++){
//         for(int j=1;j<=i;j++){
//             cout<<count<<" ";
//             count++;
//         }
//         cout<<endl;
//     }
//     return 0;
// }

/*
    butterfly pattern
    *      *
    **    **
    ***  ***
    ********
    ********
    ***  ***
    **    **
    *      *
*/
// #include<iostream>
// using namespace std;
// int main()
// {
//     int n;
//     cin>>n;
//     //upper half
//     for(int i=1;i<=n;i++){
//         for(int j=1;j<=i;j++){
//             cout<<"*";
//         }
//         int space = 2*n-2*i;
//         for(int j=1;j<=space;j++){
//             cout<<" ";
//         }
//         for(int j=1;j<=i;j++){
//             cout<<"*";
//         }
//         cout<<endl;
//     }
//     //lower half
//     for(int i=n;i>=1;i--){
//         for(int j=1;j<=i;j++){
//             cout<<"*";
//         }
//         int space = 2*n-2*i;
//         for(int j=1;j<=space;j++){
//             cout<<" ";
//         }
//         for(int j=1;j<=i;j++){
//             cout<<"*";
//         }
//         cout<<endl;
//     }
//     return 0;
// }

/*
    Inverted half pyramid using nos
    1 2 3 4 5
    1 2 3 4
    1 2 3
    1 2
    1
*/
// #include<iostream>
// using namespace std;
// int main()
// {
//     int row;
//     cin>>row;
//     for(int i=row;i>=1;i--){
//         for(int j=1;j<=i;j++){
//             cout<<j<<" ";
//         }
//         cout<<endl;
//     }
//     return 0;
// }

/*
    0-1 pattern
    1
    0 1
    1 0 1
    0 1 0 1
    1 0 1 0 1
*/
// #include<iostream>
// using namespace std;
// int main()
// {
//     int row;
//     cin>>row;
//     for(int i=1;i<=row;i++){
//         for(int j=1;j<=i;j++){
//             if((i+j)%2==0)
//             cout<<"1 ";
//             else
//             cout<<"0 ";
//         }
//         cout<<endl;
//     }
//     return 0;
// }

/*
    rhombus pattern
        *****
       *****
      *****
     *****
    *****
*/
// #include<iostream>
// using namespace std;
// int main()
// {
//     int row;
//     cin>>row;
//     for(int i=1;i<=row;i++){
//         for(int j=1;j<=row-i;j++){
//             cout<<" ";
//         }
//         for(int j=1;j<=row;j++){
//             cout<<"*";
//         }
//         cout<<endl;
//     }
//     return 0;
// }

/*
    number pattern
        1
       1 2
      1 2 3
     1 2 3 4
    1 2 3 4 5
*/
// #include<iostream>
// using namespace std;
// int main()
// {
//     int row;
//     cin>>row;
//     for(int i=1;i<=row;i++){
//         for(int j=1;j<=row-i;j++){
//             cout<<" ";
//         }
//         for(int j=1;j<=i;j++){
//             cout<<j<<" ";
//         }
//         cout<<endl;
//     }
//     return 0;
// }

/*
    pallindrome pattern
            1
           212
          32123
         4321234
        543212345
*/
// #include<iostream>
// using namespace std;
// int main()
// {
//     int row;
//     cin>>row;
//     for(int i=1;i<=row;i++){
//         for(int j=1;j<=row-i;j++){
//             cout<<" ";
//         }
//         for(int j=i;j>=1;j--){
//             cout<<j;
//         }
//         for(int k=2;k<=i;k++){
//             cout<<k;
//         }
//         cout<<endl;
//     }
//     return 0;
// }

/*
    star pattern
        *
       ***
      *****
     *******
     *******
      *****
       ***
        *
*/
// #include<iostream>
// using namespace std;
// int main()
// {
//     int row;
//     cin>>row;
//     //upper half
//     for(int i=1;i<=row;i++){
//         for(int j=1;j<=row-i;j++){
//             cout<<" ";
//         }
//         for(int j=i;j>=1;j--){
//             cout<<"*";
//         }
//         for(int k=2;k<=i;k++){
//             cout<<"*";
//         }
//         cout<<endl;
//     }
//     //lower half
//     for(int i=row;i>=1;i--){
//         for(int j=1;j<=row-i;j++){
//             cout<<" ";
//         }
//         for(int j=i;j>=1;j--){
//             cout<<"*";
//         }
//         for(int k=2;k<=i;k++){
//             cout<<"*";
//         }
//         cout<<endl;
//     }
//     return 0;
// }

/*
    zig zag pattern
    *   *   *   *
   * * * * * * * *
  *   *   *   *   *
*/
// #include<iostream>
// using namespace std;
// int main()
// {
//     int row;
//     cin>>row;
//     for(int i=1;i<=3;i++){
//         for(int j=1;j<=row;j++){
//             if((i+j)%4==0 || (i==2 && j%4==0))
//             cout<<"*";
//             else
//             cout<<" ";
//         }
//         cout<<endl;
//     }
//     return 0;
// }

/*
    v pattern
    1        1
    12      21
    123    321
    1234  4321
    1234554321

*/
// #include<iostream>
// using namespace std;
// int main()
// {
//     int n;
//     cin>>n;
//     for(int i=1;i<=n;i++){
//         for(int j=1;j<=i;j++){
//             cout<<j;
//         }
//         int space = 2*n-2*i+1;
//         for(int j=1;j<space;j++){
//             cout<<" ";
//         }
//         for(int j=i;j>=1;j--){
//             cout<<j;
//         }

//         cout<<endl;
//     }
//     return 0;
// }

/*
    Number star pattern
        1234554321
        1234**4321
        123****321
        12******21
        1********1
*/
/*
    #include<iostream>
    using namespace std;
    int main(){
        int n;
        cin>>n;
        for(int i=n;i>=1;i--){
            for(int j=1;j<=i;j++){
                cout<<j;
            }
            int space = 2*n-2*i+1;
            for(int j=1;j<space;j++){
                cout<<"*";
            }
            for(int j=i;j>=1;j--){
                cout<<j;
            }
            cout<<endl;
        }
        return 0;
    }
*/

/*
    pascals triangle
        1
        1 1
        1 2 1
        1 3 3 1
        1 4 6 4 1
*/
// #include<iostream>
// using namespace std;
// int fact(int n){
//     int fact=1;
//     for(int i=2;i<=n;i++){
//         fact*=i;
//     }
//     return fact;
// }
// int main()
// {
//     int n;
//     cin>>n;
//     for(int i=0;i<n;i++){
//         for(int j=0;j<=i;j++){
//             cout<<fact(i)/(fact(j)*fact(i-j))<<" ";
//         }
//         cout<<endl;
//     }
//     return 0;
// }

/*
    Rhombus pallindrome
        1
       212
      32123
     4321234
    543212345
     4321234
      32123
       212
        1
*/
// #include <iostream>
// using namespace std;
// int main()
// {
//     int n;
//     cin >> n;
//     // upper half
//     for (int i = 1; i <= n; i++)
//     {
//         for (int j = 1; j <= (n - i); j++)
//         {
//             cout << " ";
//         }
//         for (int j = i; j >= 1; j--)
//         {
//             cout << j;
//         }
//         for (int k = 2; k <= i; k++)
//         {
//             cout << k;
//         }
//         cout << endl;
//     }
//     // lower half
//     for (int i = n - 1; i >= 1; i--)
//     {
//         for (int j = 1; j <= (n - i); j++)
//         {
//             cout << " ";
//         }
//         for (int j = i; j >= 1; j--)
//         {
//             cout << j;
//         }
//         for (int k = 2; k <= i; k++)
//         {
//             cout << k;
//         }
//         cout << endl;
//     }
//     return 0;
// }
/*
    Diamond of Stars
            *
           ***
          *****
           ***
            *
*/
// #include <iostream>
// using namespace std;
// int main()
// {
//     int n; 
//     cin >> n;
//     // upperhalf
//     for (int i = 0; i <= n / 2; i++)
//     {
//         for (int j = n / 2; j >= i + 1; j--)
//             cout << " ";
//         for (int j = 0; j <= i * 2; j++)
//             cout << "*";
//         cout << endl;
//     }
//     // lower half
//     for (int i = n / 2; i >= 0; i--)
//     {
//         for (int k = n / 2; k >= i; k--)
//             cout << " ";
//         for (int j = 0; j < i * 2 - 1; j++)
//             cout << "*";
//         cout << endl;
//     }
//     return 0;
// }

/*
    4 4 4 4 4 4 4
    4 3 3 3 3 3 4
    4 3 2 2 2 3 4
    4 3 2 1 2 3 4
    4 3 2 2 2 3 4
    4 3 3 3 3 3 4
    4 4 4 4 4 4 4
*/
// #include<bits/stdc++.h>
// using namespace std;
// void printSquare(int n)
// {
//     int size = 2 * n - 1;
//     for (int i = 0; i < size; i++)
//     {
//         for (int j = 0; j < size; j++)
//         {
//             int formula = n - min(min(i, j), min((size - 1) - i, (size - 1) - j));
//             cout << formula << " ";
//         }
//         cout << endl;
//     }
// }
// int main()
// {
//     int n;
//     cin>>n;
//     printSquare(n);
//     return 0;
// }