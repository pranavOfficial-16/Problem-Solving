#include <bits/stdc++.h>
using namespace std;
template <typename T>
class Node
{
public:
    T data;
    Node<T> *next;
    Node(T data)
    {
        this->data = data;
        next = NULL;
    }
};
template <typename T>
class QueueUsingLinkedList
{
    Node<T> *head;
    Node<T> *tail;
    int size;

public:
    QueueUsingLinkedList()
    {
        head = NULL;
        tail = NULL;
        size = 0;
    }

    int getSize() { return size; }

    bool isEmpty() { return size == 0; }
 
    T front()
    {
        if (isEmpty())
            return 0;
        return head->data;
    }

    void enqueue(T element)
    {
        Node<T> *newnode = new Node<T>(element);
        if (head == NULL)
        {
            head = newnode;
            tail = newnode;
        }
        else
        {
            tail->next = newnode;
            tail = newnode;
        }
        size++;
    }

    T dequeue()
    {
        if (isEmpty())
            return 0;
        T ans = head->data;
        head = head->next;
        size--;
        return ans;
    }
};
int main()
{
    QueueUsingLinkedList<int> q;
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