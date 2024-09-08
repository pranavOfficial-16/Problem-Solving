#include "../Introduction/SingleLinkedListSyntax.cpp"

// here we used a concept of dummy nodes to reduce the space complexity 
// TC-> O(n1+n2), SC-> O(1)
Node *mergeTwoLists(Node *list1, Node *list2)
{
    Node *t1 = list1;
    Node *t2 = list2;
    Node *dnode = new Node(-1);
    Node *temp = dnode;
    while (t1 != NULL && t2 != NULL)
    {
        if (t1->data < t2->data)
        {
            temp->next = t1;
            temp = t1;
            t1 = t1->next;
        }
        else
        {
            temp->next = t2;
            temp = t2;
            t2 = t2->next;
        }
    }
    if (t1)
        temp->next = t1;
    else
        temp->next = t2;
    return dnode->next;
}
