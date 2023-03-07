#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,digit,i=0,dec=0;
    cin>>n;
    while(n!=0){
        digit = n%10;
        n=n/10;
        dec+=digit*pow(2,i);
        i++;
    }
    cout<<dec;
    return 0;
}