#include <bits/stdc++.h>
using namespace std;
int main()
{
    int i = 10;
    int *p = &i;
    cout << "data = " << i << endl;
    cout << "data = " << *p << endl;
    cout << "address = " << &i << endl;
    cout << "address = " << p << endl;
    i++;
    cout << "data = " << i << endl;
    cout << "data = " << *p << endl;
    i = 20;
    cout << "data = " << i << endl;
    cout << "data = " << *p << endl;
    *p = 56;
    cout << "data = " << i << endl;
    cout << "data = " << *p << endl;
    (*p)++;
    cout << "data = " << i << endl;
    cout << "data = " << *p << endl;
    *p++;
    cout << "data = " << i << endl;
    cout << "data = " << *p << endl;
    int a[3] = {1,5,6};
    cout << ++(*a) << endl;
    cout << (*a)-- << endl;
    cout << *a << endl;
}