#include <iostream>
using namespace std;
void sumOfTwoArrays(int *a1, int n1, int *a2, int n2, int *a3)
{
    int num1 = a1[0], num2 = a2[0], num3, n3, rem, index,count=0;
    for (int i = 1; i < n1; i++)
        num1 = num1 * 10 + a1[i];
    for (int i = 1; i < n2; i++)
        num2 = num2 * 10 + a2[i];
    num3 = num1 + num2;
    n3 = max(n1, n2) + 1;
    index = n3-1;
    while (num3)
    {
        rem = num3 % 10;
        a3[index--] = rem;
        num3 = num3/10;
        count++;
    }
    if(n3!=count)
    a3[index--] = 0;
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
    int n3 = max(n1,n2)+1;
    int a3[n3];
    sumOfTwoArrays(a1, n1, a2, n2, a3);
    for (int i = 0; i < n3; i++)
        cout << a3[i] << " ";
    return 0;
}