#include <bits/stdc++.h>
using namespace std;
template <typename T>
class StackUsingTemplates
{
    T *data;
    int nextIndex;
    int capacity;

public:
    StackUsingTemplates()
    {
        capacity = 4;
        data = new T[capacity];
        nextIndex = 0;
    }

    int size()
    {
        return nextIndex;
    }

    bool isEmpty()
    {
        return nextIndex == 0;
    }

    void push(int element)
    {
        if (nextIndex == capacity)
        {
            T *newData = new T[2 * capacity];
            for (int i = 0; i < capacity; i++)
                newData[i] = data[i];
            capacity *= 2;
            delete[] data;
            data = newData;
        }
        data[nextIndex] = element;
        nextIndex++;
    }

    T pop()
    {
        if (isEmpty())
        {
            cout << "stack is empty" << endl;
            return 0;
        }
        nextIndex--;
        return data[nextIndex];
    }

    T top()
    {
        if (isEmpty())
        {
            cout << "stack is empty" << endl;
            return 0;
        }
        return data[nextIndex - 1];
    }
};
int main()
{
    StackUsingTemplates<char> s;
    s.push('a');
    s.push('b');
    s.push('c');
    s.push('d');
    s.push('e');
    cout << s.top() << endl;
    cout << s.pop() << endl;
    cout << s.pop() << endl;
    cout << s.pop() << endl;
    cout << s.size() << endl;
    cout << s.isEmpty() << endl;
    return 0;
}