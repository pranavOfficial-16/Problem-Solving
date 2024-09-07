#include "../Introduction/SingleLinkedListSyntax.cpp"

// Dummy Node Approach (used when we need to create a new list to store)
// TC-> O(), SC-> O()
Node *addTwoNumbers(Node *l1, Node *l2)
{
    Node *t1 = l1;
    Node *t2 = l2;
    Node *dummyNode = new Node(-1);
    Node *curr = dummyNode;
    int carry = 0, sum;
    while (t1 != NULL || t2 != NULL)
    {
        sum = carry;
        if (t1)
            sum = sum + t1->data;
        if (t2)
            sum = sum + t2->data;
        Node *newNode = new Node(sum % 10);
        carry = sum / 10;
        curr->next = newNode;
        curr = newNode;
        if (t1)
            t1 = t1->next;
        if (t2)
            t2 = t2->next;
    }
    if (carry)
        curr->next = new Node(carry);
    return dummyNode->next;
}