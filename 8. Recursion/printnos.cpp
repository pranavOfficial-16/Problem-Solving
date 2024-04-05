//counting of nos in either asc or dec
#include <iostream>
using namespace std;
void print(int n)
{
    //base case
    if (n == 0)
        return; 
    
    //Recursive call
    print(n - 1);

    //processing
    cout << n << " ";
}
int main()
{
    int n;
    cin >> n;
    print(n);
    return 0;
}