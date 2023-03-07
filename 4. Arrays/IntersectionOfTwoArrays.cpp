// print the common elements of both the array
#include <bits/stdc++.h>
using namespace std;
void intersection(int *input1, int *input2, int size1, int size2)
{
    sort(input1, input1 + size1);
    sort(input2, input2 + size2);
    for (int i = 0; i < size1; i++)
    {
        for (int j = 0; j < size2; j++)
        {
            if (input1[i] == input2[j])
            {
                cout << input2[j] << " ";
                input2[j] = INT_MIN;
                break;
            }
        }
    }
}
int main()
{
    int n1;
    cin >> n1;
    int a1[n1];
    for (int i = 0; i < n1; i++)
        cin >> a1[i];
    int n2;
    cin >> n2;
    int a2[n2];
    for (int i = 0; i < n2; i++)
        cin >> a2[i];
    intersection(a1, a2, n1, n2);
    return 0;
}