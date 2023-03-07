#include<iostream>
#include<iomanip>
#include<math.h>
using namespace std;
double geometricSum(int k)
{
    if (k >= 1)
        return (1 / pow(2, k)) + geometricSum(k - 1);
    else
        return 1;
}
int main()
{
    int k;
    cin>>k;
    cout<<fixed<<setprecision(5)<<geometricSum(k);
    return 0;
}