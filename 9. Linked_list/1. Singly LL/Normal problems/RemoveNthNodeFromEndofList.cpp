#include "../Introduction/SingleLinkedListSyntax.cpp"

// bruteforce
// TC-> O(n) + O(cnt-n), SC-> O(1)
Node *removeNthFromEnd(Node *head, int n)
{
    int cnt = 0;
    Node *temp = head;
    while (temp != NULL)
    {
        cnt++;
        temp = temp->next;
    }
    if (cnt == n)
    {
        Node *newHead = head->next;
        delete head;
        return newHead;
    }
    int res = cnt - n;
    while (temp != NULL)
    {
        res--;
        if (res == 0)
            break;
        temp = temp->next;
    }
    Node *delnode = temp->next;
    temp->next = temp->next->next;
    delete delnode;
    return head;
}

// Optimal
// TC-> O(n), SC-> O(1)
Node *removeNthFromEnd(Node *head, int n)
{
    Node *fast = head;
    for (int i = 0; i < n; i++)
        fast = fast->next;
    if(fast == NULL){
        Node *newHead = head->next;
        delete head;
        return newHead;
    }
    Node *slow = head;
    while(fast->next != NULL){
        slow = slow->next;
        fast = fast->next;
    }
    Node *delNode = slow->next;
    slow->next = slow->next->next;
    delete delNode;
    return head;
}