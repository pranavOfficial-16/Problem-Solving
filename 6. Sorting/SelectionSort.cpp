/*
    TC -> O(N^2)
    SC -> O(1)
    ascending sort -> find the min element and swap it in begining and so on (asc)
    descending sort -> find the max element and swap it in begining and so on (dec)
    use case -> use when the array size is small

*/
#include <bits/stdc++.h>
using namespace std;
void selectionsort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int mini = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[mini])
                mini = j;
        }
        swap(arr[mini],arr[i]);
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