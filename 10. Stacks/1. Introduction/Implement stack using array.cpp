#include <bits/stdc++.h>
using namespace std;
class StackUsingArrays
{
    int *data;      // array
    int nextIndex;  // index of the array
    int capacity;   // size of the array

public:
    StackUsingArrays(int totalsize)
    {
        capacity = totalsize;
        data = new int[capacity];
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
            int *newData = new int[2 * capacity];
            for (int i = 0; i < capacity; i++)
                newData[i] = data[i];
            capacity *= 2;
            delete [] data;
            data = newData;
        }
        data[nextIndex] = element;
        nextIndex++;
    }

    int pop()
    {
        if (isEmpty())
        {
            cout << "stack is empty" << endl;
            return INT_MIN;
        }
        nextIndex--;
        return data[nextIndex];
    }

    int top()
    {
        if (isEmpty())
        {
            cout << "stack is empty" << endl;
            return INT_MIN;
        }
        return data[nextIndex - 1];
    }
};
int main()
{
    StackUsingArrays s(4);
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    s.push(50);
    cout << s.top() << endl;
    cout << s.pop() << endl;
    cout << s.pop() << endl;
    cout << s.pop() << endl;
    cout << s.size() << endl;
    cout << s.isEmpty() << endl;
    return 0;
}