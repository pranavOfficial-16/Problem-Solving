#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
    Node(int data)
    {
        this->data = data;
        next = NULL;
    }
};
Node *input()
{
    int data;
    cin >> data;
    Node *head = NULL;
    Node *tail = NULL;
    while (data != -1)
    {
        Node *newnode = new Node(data);
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
        cin >> data;
    }
    return head;
}
void print(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
}
void splitList(Node *head, Node **a, Node **b)
{
    Node *slow = head;
    Node *fast = head->next;
    while (fast != nullptr)
    {
        fast = fast->next;
        if (fast != nullptr)
        {
            slow = slow->next;
            fast = fast->next;
        }
    }
    *a = head;
    *b = slow->next;
    slow->next = nullptr;
}
int main()
{
    Node *head = input();
    Node *a, *b;
    splitList(head, &a, &b);
    cout << "First half -> ";
    while (a != NULL)
    {
        cout << a->data << " ";
        a = a->next;
    }
    cout << endl;
    cout << "Second half -> ";
    while (b != NULL)
    {
        cout << b->data << " ";
        b = b->next;
    }
    return 0;
}