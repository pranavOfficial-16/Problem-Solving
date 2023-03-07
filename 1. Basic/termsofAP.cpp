#include <iostream>
using namespace std;
int main()
{
    int n = 1, count = 0;
    int x;
    cin>>x;
    while (count != x)
    {
        int term = 3 * n + 2;
        if (term % 4 != 0)
        {
            cout<<term<<" ";
            count++;
        }
        n++;
    }
    return 0;
}
