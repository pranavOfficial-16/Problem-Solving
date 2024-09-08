#include "LengthOfLinkedList.cpp"
int main()
{
    // Statically
    Node n1(5);
    Node *head = &n1; // To maintain address of n1
    cout << n1.data << endl;
    Node n2(10);

    // Connecting nodes
    n1.next = &n2;
    n2.prev = &n1;

    cout << n1.data << " " << n1.next->data << endl;
    cout << n2.data << " " << n2.prev->data << endl;
    cout << head->data << " " << head->next->data << endl;

    // Dynamically
    Node *n3 = new Node(15);
    head = n3;
    Node *n4 = new Node(20);

    // Connecting nodes
    n3->next = n4;
    n4->prev = n3;

    printLeftToRight(head);
    printRightToLeft(head);
    cout << length(head);
}