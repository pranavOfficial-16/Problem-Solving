// stack - small size
// heap - bigger size
#include <iostream>
using namespace std;
int main()
{
    // static memory allocation - saved in stack
    int i = 5;
    int b[i];
    int n;
    cin >> n;
    //  dynamic memory allocation for 1d arrays
    //  dynamic meomory allocation - saved in heap
    int *a = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++)
    {
        cout << a[i];
    }
    // we should manually deacclocate the dynamic variable
    delete a;   // single element
    delete[] a; // array deletion
    // dynamic memory allocation for 2d arrays
    // m is rows and o is columns
    int m, o;
    cin >> m >> o;
    int **p = new int *[m];
    for (int i = 0; i < m; i++)
    {
        p[i] = new int[o];
        for (int j = 0; j < o; j++)
        {
            cin >> p[i][j];
        }
    }
    //To deallocate 2d array when it is dynamic
    for(int i=0;i<m;i++){
        delete[] p[i];
    }
    delete [] p;
    return 0;
}