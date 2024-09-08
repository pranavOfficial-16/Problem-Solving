#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
    Node *child;
    Node() : data(0), next(nullptr), child(nullptr) {};
    Node(int x) : data(x), next(nullptr), child(nullptr) {}
    Node(int x, Node *nextNode, Node *childNode) : data(x), next(nextNode), child(childNode) {}
};
Node *merge(Node *list1, Node *list2)
{
    Node *dummyNode = new Node(-1);
    Node *res = dummyNode;
    while (list1 != NULL && list2 != NULL)
    {
        if (list1->data < list2->data)
        {
            res->child = list1;
            res = list1;
            list1 = list1->child;
        }
        else
        {
            res->child = list2;
            res = list2;
            list2 = list2->child;
        }
    }
    if (list1)
        res->child = list1;
    else
        res->child = list2;
    return dummyNode->child;
}
Node *flattenLinkedList(Node *head)
{
    if (head == NULL || head->next == NULL)
        return head;
    Node *mergedHead = flattenLinkedList(head->next);
    head = merge(head, mergedHead);
    return head;
}
