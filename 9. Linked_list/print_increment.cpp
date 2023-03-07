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
void print(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << endl;
        temp = temp->next;
    }
    cout << endl;
}
void increment(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        temp->data++;
        temp = temp->next;
    }
}
int main()
{
    // static allocation
    Node n1(1);

    // To save initial node's address
    Node *head = &n1;

    Node n2(2);
    Node n3(3);
    Node n4(4);
    Node n5(5);

    n1.next = &n2;
    n2.next = &n3;
    n3.next = &n4;
    n4.next = &n5;

    print(head);
    increment(head);
    print(head);

    // To connect both node
    // n1.next = &n2;
    // cout << head->data << endl;

    // dynamic allocation (we dont use & to hold the address in dynamic)
    /*
        Node *n3 = new Node(10);
        Node *head = n3;

        Node *n4 = new Node(10);
        n3->next = n4;
    */
    return 0;
}