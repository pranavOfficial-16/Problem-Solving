#include "../Introduction/DoubleLinkedListSyntax.cpp"

// TC-> O(n), SC-> O(n-count(k))
Node *deleteAllOccurrences(Node *head, int k)
{
    Node *dummynode = new Node(-1);
    Node *temp = dummynode;
    Node *t1 = head;
    while (t1 != NULL)
    {
        if (t1->data == k)
        {
            t1 = t1->next;
            continue;
        }
        Node *newNode = new Node(t1->data);
        temp->next = newNode;
        newNode->prev = temp;
        temp = newNode;
        t1 = t1->next;
    }
    head = dummynode->next;
    // if it is not empty
    if (head != NULL)
        head->prev = NULL;

    delete dummynode;
    return head;
}