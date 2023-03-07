//counting of nos in either asc or dec
#include <iostream>
using namespace std;
void print(int n)
{
    if (n == 0)
        return; 
    /*
    ascending print
    print(n - 1);
    cout << n << " ";
    */
    // descending print
    cout << n << " ";
    print(n - 1);
}
int main()
{
    int n;
    cin >> n;
    print(n);
    return 0;
}