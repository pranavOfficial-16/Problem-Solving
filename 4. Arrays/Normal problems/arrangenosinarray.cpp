#include <iostream>
using namespace std;
int arrange(int *arr, int n)
{
    int i = 0, j = n - 1, num = 1;
    while (i <= j)
    {
        if (num % 2 == 1)
            arr[i++] = num;
        else
            arr[j--] = num;
        num++;
    }
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}
int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    arrange(arr,n);
    return 0;
}