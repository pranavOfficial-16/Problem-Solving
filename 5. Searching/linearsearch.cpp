// search and return the index value of the element or else return -1
#include <iostream>
using namespace std;
int linearSearch(int *arr, int n, int x)
{
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == x)
            return i;
    }
    return -1;
}
int main()
{
    int n, x;
    cin >> n;
    int *arr = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    // Element to be searched
    cin >> x;
    cout << linearSearch(arr, n, x);
    return 0;
}