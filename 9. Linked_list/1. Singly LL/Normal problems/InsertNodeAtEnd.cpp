#include "../Introduction/SingleLinkedListSyntax.cpp"
Node *insertAtEnd(Node *head, int x)
{

    // if linked list is empty
    if (head == NULL)
    {
        Node *newNode = new Node(x);
        head = newNode;
        return head;
    }

    // if linked list is not empty
    Node *temp = head;
    while (temp->next != NULL)
        temp = temp->next;
    Node *newNode = new Node(x);
    temp->next = newNode;
    return head;
}
int main(){
    Node *head = input();
    print(head);
    int x;
    cin >> x;
    insertAtEnd(head, x);
    print(head);
}