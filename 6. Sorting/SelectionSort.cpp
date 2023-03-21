/*
    TC -> worst - O(N^2)  best - O(N^2)
    Selection sort -> find the min element and swap it in begining and so on (asc)
    Selection sort -> find the max element and swap it in begining and so on (dec)
*/
#include <bits/stdc++.h>
using namespace std;
void selectionsort(int arr[], int n)
{
    for (int i = 0; i <= n - 2; i++)
    {
        int mini = i;
        for (int j = i; j <= n - 1; j++)
        {
            if (arr[j] < arr[mini])
                mini = j;
        }
        int temp = arr[mini];
        arr[mini] = arr[i];
        arr[i] = temp;
    }
}
int main()
{
    int n;
    cin >> n;
    int *arr = new int[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    selectionsort(arr, n);
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    return 0;
}