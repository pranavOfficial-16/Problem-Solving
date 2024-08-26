/*
    TC -> O(N^2)
    SC -> O(1)
    ascending sort -> Takes an element and place it in its correct order (asc)
    descending sort -> Takes an element and place it in its correct order (des)
    use case -> Adaptable, best for small input arrays
    Note -> Insertion sort is a more efficient sorting algorithm than selection and bubble sort
*/
#include <bits/stdc++.h>
using namespace std;
void insertionSort(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        int j = i;
        while (j > 0 && arr[j - 1] > arr[j])
        {
            swap(arr[j], arr[j - 1]);
            j--;
        }
    }
}
int main()
{
    int n;
    cin >> n;
    int *arr = new int[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    insertionSort(arr, n);
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    return 0;
}
