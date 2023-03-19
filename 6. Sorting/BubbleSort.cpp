/*
    Bubble sort
    Reapetedly swap two adj elements if they are in wrong order
    L>R = wrong order (asc)
    L<R = wrong order (dec)
*/
#include <iostream>
using namespace std;
void bubbleSort(int *a, int n)
{
    int temp;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (a[j] > a[j + 1])
            {
                temp = a[j + 1];
                a[j + 1] = a[j];
                a[j] = temp;
            }
        }
    }
}
int main()
{
    int n;
    cin >> n;
    int *a = new int[n];
    for (int i = 0; i < n; i++)
    cin >> a[i];
    bubbleSort(a,n);
    for (int i = 0; i < n; i++)
    cout << a[i] << " ";
    return 0;
}