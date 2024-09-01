#include "Node.cpp"
void print(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
}
int main()
{
    // Statically
    Node n1(1);
    Node *head = &n1; // To maintain address of n1
    Node n2(2);

    // Connecting nodes
    n1.next = &n2;

    cout << n1.data << " " << n2.data << endl;
    cout << head->data << " " << head->next->data << endl;

    // Dynamically
    Node *n3 = new Node(10);
    head = n3;
    Node *n4 = new Node(20);

    // Connecting nodes
    n3->next = n4;

    print(head);
}