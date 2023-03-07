#include <iostream>
#include <cmath>
using namespace std;
int main()
{
    int s, e, w;
    cin >> s >> e >> w;
    float celcius;
    for (int i = s; i <= e; i += w)
    {
        celcius = (i - 32) * 5.0 / 9.0;
        cout << i << " " << (int)celcius << endl;
    }
}
