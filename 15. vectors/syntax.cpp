// vectors are inbuild dynamic array
#include<bits/stdc++.h>
using namespace std;
int main()
{
    // dynamic
    vector<int> *v = new vector<int>();
    //static
    vector<int> v1;
    v1.push_back(10);
    v1.push_back(20);
    v1.push_back(30);
    /*
        v[] we use for only get and update (not to insert)
    */
   cout<<v1.at(1)<<endl;
    for(int i : v1)
        cout<<i<<endl;
    return 0;
}