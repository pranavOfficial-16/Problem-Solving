#include "../Introduction/DoubleLinkedListSyntax.cpp"

Node *removeDuplicates(Node *head)
{
    if (head == NULL || head->next == NULL)
        return head;

    set<int> unique;
    Node *temp = head;

    while (temp != NULL)
    {
        unique.insert(temp->data);
        temp = temp->next;
    }

    // if no unique
    if (unique.empty())
        return NULL;

    temp = head;
    Node *dummynode = new Node(-1);
    Node *curr = dummynode;

    for (auto &node : unique)
    {
        Node *newnode = new Node(node);
        curr->next = newnode;
        newnode->prev = curr;
        curr = newnode;
    }

    head = dummynode->next;

    // if it is not empty
    if (head != NULL)
        head->prev = NULL;
    
    delete dummynode;
    return head;
}