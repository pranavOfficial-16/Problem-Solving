#include "../Introduction/SingleLinkedListSyntax.cpp"

// sort by 0s, 1s, 2s
Node *segregate(Node *head)
{
    vector<int> count(3, 0);
    Node *temp = head;
    while (temp != NULL)
    {
        count[temp->data]++;
        temp = temp->next;
    }
    temp = head;
    int index = 0;
    while (temp != NULL)
    {
        if (count[index] == 0)
            index++;
        else
        {
            temp->data = index;
            count[index]--;
            temp = temp->next;
        }
    }
    return head;
}
