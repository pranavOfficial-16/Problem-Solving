#include <bits/stdc++.h>
using namespace std;
template <typename T, typename V>
class Pair
{
    T x;
    V y;

public:
    void setX(T x)
    {
        this->x = x;
    }
    T getX()
    {
        return x;
    }
    void setY(V y)
    {
        this->y = y;
    }
    V getY()
    {
        return y;
    }
};
int main()
{
    Pair<int,double> p1,p2;
    p1.setX(10);
    p1.setY(100.43);
    cout << p1.getX()<<endl;
    cout << p1.getY()<<endl;
    p2.setX(20);
    p2.setY(56.7);
    cout << p2.getX() << endl;
    cout << p2.getY() << endl;
    return 0;
}