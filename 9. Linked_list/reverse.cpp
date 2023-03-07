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

// recursive approach
// Node *reverse(Node *head)
// {
//     if (head == NULL || head->next == NULL)
//         return head;
//     Node *smallans = reverse(head->next);
//     Node *temp = smallans;
//     while (temp->next != NULL)
//         temp = temp->next;
//     temp->next = head;
//     head->next = NULL;
//     return smallans;
// }

// Iterative approach
Node* reverse(Node *head)
{
    Node *current = head;
    Node *before = NULL;
    Node *after = NULL;
    while (current != NULL)
    {
        after = current->next;
        current->next = before;
        before = current;
        current = after;
    }
    head = before;
    return head;
}

int main()
{
    Node *head = input();
    head = reverse(head);
    print(head);
    return 0;
}