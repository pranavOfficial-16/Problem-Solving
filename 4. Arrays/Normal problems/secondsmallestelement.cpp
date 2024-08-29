// To find the second smallest element
#include <bits/stdc++.h>
using namespace std;
int getSecondSmallest(int *arr, int n){
    int min = INT_MAX;
    int secondMin = INT_MAX;
    for(int i=0; i < n; i++){
        if(arr[i] < min){
            secondMin = min;
            min = arr[i];
        }
        else if(arr[i] < secondMin && arr[i] != min){
            secondMin = arr[i];
        }
    }
    return secondMin;
}
int main()
{
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    cout <<getSecondSmallest(a,n);
}
