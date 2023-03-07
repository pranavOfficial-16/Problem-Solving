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
Node *skipMdeleteN(Node *head, int m, int n)
{
    if(m == 0)
        return NULL;
    Node *current = head;
    Node *temp;
    while (current != NULL)
    {
        for (int count = 1; count < m && current != NULL; count++)
            current = current->next;
        if (current == NULL)
            return head;
        temp = current->next;
        for (int count = 1; count <= n && temp != NULL; count++)
            temp = temp->next;
        current->next = temp;
        current = temp;
    }
    return head;
}
int main()
{
    Node *head = input();
    int m, n;
    cin >> m >> n;
    head = skipMdeleteN(head, m, n);
    print(head);
    return 0;
}