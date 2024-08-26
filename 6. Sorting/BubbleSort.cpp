/*
    TC -> O(N^2)
    SC -> O(1)
    ascending sort -> pushes the max to the last by adjacent swaps (asc)
    descending sort -> pushes the min to the last by adjacent swaps (des)
    use case -> At ith round, ith largest element is kept in the right place (asc)
*/
#include <iostream>
using namespace std;
void bubbleSort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int didswap = 0;
        for (int j = 0; j < n - i; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
                didswap = 1;
            }
        }
        if (didswap == 0)
            break;
    }
}
int main()
{
    int n;
    cin >> n;
    int *arr = new int[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    bubbleSort(arr, n);
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    return 0;
}