#include "DoubleLinkedListSyntax.cpp"
Node *deleteLastNode(Node *head)
{
    Node *temp = head;

    // if only one node is there
    if (temp->prev == nullptr && temp->next == nullptr)
    {
        Node *newNode = temp->next;
        head = newNode;
        return head;
    }

    while (temp->next != NULL)
        temp = temp->next;

    Node *lastnode = temp;
    temp->prev->next = nullptr;
    temp->prev = nullptr;
    delete lastnode;
    return head;
}