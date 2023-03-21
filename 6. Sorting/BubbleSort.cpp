/*
    TC -> worst - O(N^2)  best - O(N)
    Bubble sort -> pushes the max to the last by adjacent swaps (asc)
    Bubble sort -> pushes the min to the last by adjacent swaps (des)
*/
#include <iostream>
using namespace std;
void bubbleSort(int arr[], int n)
{
    for (int i = n - 1; i >= 0; i--)
    {
        int didswap = 0;
        for (int j = 0; j <= i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                didswap = 1;
            }
        }
        if(didswap == 0)
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