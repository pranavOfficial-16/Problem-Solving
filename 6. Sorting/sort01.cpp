// sort an array containing zeros and ones
#include <iostream>
using namespace std;
void sortZeroesAndOne(int a[], int n)
{
    // Approach - 1

    // int temp[n];
    // for (int i = 0; i < n; i++)
    //     temp[i] = a[i];
    // int j = 0, k = n - 1;
    // for (int i = 0; i < n; i++)
    // {
    //     if (temp[i] == 0)
    //         a[j++] = 0;
    //     else
    //         a[k--] = 1;
    // }

    // Approach - 2

    int left = 0, right = n - 1;
    while (left < right)
    {

        if (a[left] == 0)
            left++;
            
        else if (a[right] == 1)
            right--;

        else if (a[left] == 1 && a[right] == 0)
        {
            swap(a[left], a[right]);
            left++;
            right--;
        }
        
    }
}
int main()
{
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    sortZeroesAndOne(a, n);
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
    return 0;
}