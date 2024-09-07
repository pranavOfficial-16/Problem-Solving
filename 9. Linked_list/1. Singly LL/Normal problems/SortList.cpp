#include "../Introduction/SingleLinkedListSyntax.cpp"

// Using merge sort in linked list
// TC-> O(nlogn), SC-> O(1)
Node *midPoint(Node *head)
{
    Node *slow = head;
    Node *fast = head->next;
    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}
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
Node *sortList(Node *head)
{
    if (head == NULL || head->next == NULL)
        return head;

    Node *middle = midPoint(head);

    Node *lefthead = head;
    Node *righthead = middle->next;
    middle->next = NULL;

    lefthead = sortList(lefthead);
    righthead = sortList(righthead);

    head = mergeTwoLists(lefthead, righthead);
    return head;
}