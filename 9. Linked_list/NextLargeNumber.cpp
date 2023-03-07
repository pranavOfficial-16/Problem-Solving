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
Node *newNode(int data)
{
    Node *new_node = new Node(data);
    return new_node;
}
Node *reverse(Node *head)
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
Node* addone(Node* head){
    Node *result = head;
    Node *temp;
    int carry = 1, sum;
    while (head != NULL) 
    {
        sum = carry + head->data;
        carry = (sum >= 10) ? 1 : 0;
        sum = sum % 10;
        head->data = sum;
        temp = head;
        head = head->next;
    }
    if (carry > 0)
        temp->next = newNode(carry);
    return result;
}
Node* NextLargeNumber(Node *head)
{
    head = reverse(head);
    head = addone(head);
    return reverse(head);
}
int main()
{
    Node *head = input();
    head = NextLargeNumber(head);
    print(head);
    return 0;
}
