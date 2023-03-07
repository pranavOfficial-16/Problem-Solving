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
Node *insertNode(Node *head, int i, int value)
{
    Node *newnode = new Node(value);
    int count = 0;
    Node *temp = head;
    if (i == 0)
    {
        newnode->next = head;
        head = newnode;
        return head;
    }
    while (temp != NULL && count < i - 1)
    {
        temp = temp->next;
        count++;
    }
    if (temp != NULL)
    {
        newnode->next = temp->next;
        temp->next = newnode;
    }
    return head;
}
// recursive insert node in the linked list
/*
    Node* insertNode(Node *head, int i, int data) {
        // base case
        if(head==NULL)
            return NULL;
        if(i==0){
            Node *temp=new Node(data);
            temp->next=head;
            return temp;
        }
        if(i==1){
            Node *temp=new Node(data);
            temp->next=head->next;
            head->next=temp;
            return head;
        }
        Node* current=insertNode(head->next,i-1,data);
        return head;
    }
*/
int main()
{
    Node *head = input();
    int i, value;
    cin >> i >> value;
    cout << "OLD LIST -> ";
    print(head);
    head = insertNode(head, i, value);
    cout << endl;
    cout << "NEW LIST -> ";
    print(head);
    return 0;
}