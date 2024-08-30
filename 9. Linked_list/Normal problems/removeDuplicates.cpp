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
Node *removeDuplicates(Node *head)
{
    if (head == NULL)
        return NULL;
    Node *current = head;
    Node *next;
    while (current->next != NULL)
    {
        if (current->data == current->next->data)
        {
            next = current->next->next;
            current->next = next;
        }
        else
            current = current->next;
    }
    return head;
}
int main()
{
    Node *head = input();
    head = removeDuplicates(head);
    print(head);
    return 0;
}