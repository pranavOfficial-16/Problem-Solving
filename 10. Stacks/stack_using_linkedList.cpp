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
class StackUsingLinkedList
{
    Node<T> *head;
    T size;

public:
    StackUsingLinkedList()
    {
        head = NULL;
        size = 0;
    }
    T getSize()
    {
        return size;
    }
    bool isEmpty()
    {
        return size == 0;
    }
    void push(T element)
    {
        Node<T> *newnode = new Node<T>(element);
        newnode->next = head;
        head = newnode;
        size++;
    }
    T pop()
    {
        if (isEmpty())
            return 0;
        T ans = head->data;
        head = head->next;
        size--;
        return ans;
    }
    T top()
    {
        if (isEmpty())
            return 0;
        return head->data;
    }
};
int main()
{
    StackUsingLinkedList<int> s;
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    s.push(50);
    s.push(60);
    cout << s.pop() << endl;
    cout << s.pop() << endl;
    cout << s.pop() << endl;
    cout << s.pop() << endl;
    cout << s.pop() << endl;
    cout << s.top() << endl;
    cout << s.getSize() << endl;
    cout << s.isEmpty() << endl;
    return 0;
}