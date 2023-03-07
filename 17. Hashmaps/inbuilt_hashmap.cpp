#include <bits/stdc++.h>
using namespace std;
int main()
{
    unordered_map<string, int> ourmap;

    // insert
    pair<string, int> p("abc", 1);
    ourmap.insert(p);
    ourmap["def"] = 2;

    // find or access
    cout << ourmap["abc"] << endl;
    cout << ourmap.at("def") << endl;

    //cout << ourmap.at("ghi") << endl; // throws error   
    cout << "size : " << ourmap.size() << endl;
    cout << ourmap["ghi"] << endl;    // gives default value 0
    cout << "size : " << ourmap.size() << endl;

    // check Presense
    if (ourmap.count("ghi") > 0)
    {
        cout << "ghi is present" << endl;
    }
    // erase
    ourmap.erase("ghi");
    cout << "size : " << ourmap.size() << endl;
    if (ourmap.count("ghi") > 0)
    {
        cout << "ghi is present" << endl;
    }
}