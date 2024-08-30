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
Node *newNode(int data)
{
    Node *new_node = new Node(data);
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
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
void deleteAlternateNodes(Node *head)
{
    if (head == NULL)
        return;
    Node *prev = head;
    Node *node = head->next;
    while (prev != NULL && node != NULL)
    {
        prev->next = node->next;
        prev = prev->next;
        if (prev != NULL)
            node = prev->next;
    }
}
int main()
{
    Node *head = input();
    deleteAlternateNodes(head);
    print(head);
    delete head;
    return 0;
}