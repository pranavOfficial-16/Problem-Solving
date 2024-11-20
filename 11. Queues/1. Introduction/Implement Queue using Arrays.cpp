#include <bits/stdc++.h>
using namespace std;
class QueueUsingArrays
{
    int *data;
    int nextIndex;
    int firstIndex;
    int size;
    int capacity;

public:
    QueueUsingArrays(int s)
    {
        data = new int[s];
        nextIndex = 0;
        firstIndex = -1;
        size = 0;
        capacity = s;
    }

    int getSize()
    {
        return size;
    }

    bool isEmpty()
    {
        return size == 0;
    }

    void enqueue(int element)
    {
        if (size == capacity)
        {
            int *newData = new int[2 * capacity];
            int j = 0;
            for (int i = firstIndex; i < capacity; i++)
                newData[j++] = data[i];
            for (int i = 0; i < firstIndex; i++)
                newData[j++] = data[i];
            delete[] data;
            data = newData;
            firstIndex = 0;
            nextIndex = capacity;
            capacity *= 2;
        }
        data[nextIndex] = element;
        nextIndex = (nextIndex + 1) % capacity;
        if (firstIndex == -1)
            firstIndex = 0;
        size++;
    }

    int front()
    {
        if (isEmpty())
        {
            cout << "Queue is empty" << endl;
            return 0;
        }
        return data[firstIndex];
    }

    int dequeue()
    {
        if (isEmpty())
        {
            cout << "Queue is empty" << endl;
            return 0;
        }
        int ans = data[firstIndex];
        firstIndex = (firstIndex + 1) % capacity;
        size--;
        if (size == 0)
        {
            firstIndex = -1;
            size = 0;
        }
        return ans;
    }
};
int main()
{
    QueueUsingArrays q(5);
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    q.enqueue(50);
    q.enqueue(60);
    cout << q.front() << endl;
    cout << q.dequeue() << endl;
    cout << q.dequeue() << endl;
    cout << q.dequeue() << endl;
    cout << q.front() << endl;
    cout << q.getSize() << endl;
    cout << q.isEmpty() << endl;
    return 0;
}