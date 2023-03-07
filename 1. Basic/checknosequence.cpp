#include <iostream>
using namespace std;
int main()
{
    int s, current, previous, n;
    cin >> n;
    cin >> previous;
    s = 2;
    bool isDec = true;
    while (s <= n)
    {
        cin >> current;
        if (current == previous)
        {
            cout << "false" << endl;
            return 0;
        }
        if (current < previous)
        {
            if (isDec == false)
            {
                cout << "false" << endl;
                return 0;
            }
        }
        else
        {
            if (isDec == true)
            {
                isDec = false;
            }
        }
        previous = current;
        s++;
    }
    cout << "true" << endl;
}