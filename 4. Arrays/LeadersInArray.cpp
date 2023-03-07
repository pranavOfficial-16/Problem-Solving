#include<iostream>
using namespace std;
void Leaders(int *a, int n)
{
    for (int i = 0; i < n; i++)
    {
        int j;
        for (j = i + 1; j < n; j++)
        {
            if (a[i] < a[j])
                break;
        }
        if (j == n)
            cout << a[i] << " ";
    }
}
int main()
{
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
        cin>>a[i];
    Leaders(a,n);
    return 0;
}