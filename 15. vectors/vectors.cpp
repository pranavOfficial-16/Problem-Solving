// vectors are inbuild dynamic array
#include <iostream>
#include <vector>
using namespace std;
int main()
{
    // static creation of vector
    vector<int> v;
    /*
        dynamic creation of vector
        vector<int> *vp = new vector<int>();
    */
    for (int i = 1; i <= 5; i++)
        v.push_back(i);
    cout << "Output of begin and end: ";
    for (auto i = v.begin(); i != v.end(); i++)
        cout << *i << " ";
    v.pop_back();
    cout << "\nOutput after pop: ";
    for (auto i = v.begin(); i != v.end(); ++i)
        cout << *i << " ";
    cout << "\nOutput of rbegin and rend: ";
    for (auto ir = v.rbegin(); ir != v.rend(); ++ir)
        cout << *ir << " ";
    cout << "\nOutput of crbegin and crend : ";
    for (auto ir = v.crbegin(); ir != v.crend(); ++ir)
        cout << *ir << " ";
    return 0;
    // 2d vectors
    vector<vector<int>> vect{
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}};
    //method-1
    for (int i = 0; i < vect.size(); i++)
    {
        for (int j = 0; j < vect[i].size(); j++)
        {
            cout << vect[i][j] << " ";
        }
        cout << endl;
    }
    //method-2
    for (vector<int> vect1D : vect)
    {
        for (int x : vect1D)
        {
            cout << x << " ";
        }
        cout << endl;
    }
    //for declaring 2d vector
    int n=3;
    int m=4;
    vector<vector<int>> vec(n, vector<int>(m));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << vec[i][j] << " ";
        }
        cout << endl;
    }
}
