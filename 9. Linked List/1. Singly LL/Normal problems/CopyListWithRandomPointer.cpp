#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
    Node *random;
    Node() : data(0), next(nullptr), random(nullptr) {};
    Node(int x) : data(x), next(nullptr), random(nullptr) {}
    Node(int x, Node *nextNode, Node *randomNode) : data(x), next(nextNode), random(randomNode) {}
};

// Bruteforce approach
// store it in hashmap as use it to create a copy list
// TC-> O(2n), SC-> O(n) + O(n)
Node *copyRandomList(Node *head)
{
    Node *temp = head;
    unordered_map<Node *, Node *> mpp;
    while (temp != NULL)
    {
        Node *newNode = new Node(temp->data);
        mpp[temp] = newNode;
        temp = temp->next;
    }

    temp = head;
    while (temp != NULL)
    {
        Node *copyNode = mpp[temp];
        copyNode->next = mpp[temp->next];
        copyNode->random = mpp[temp->random];
        temp = temp->next;
    }
    return mpp[head];
}

// Optimal approach

// Done in three steps
// 1. Insert copy nodes in between
// 2. Connect Random Pointers
// 3. Connect Next Pointers

// TC-> O(3n), SC-> O(n)
Node *copyRandomList(Node *head)
{
    // step 1 -> Insert copy nodes in between
    Node *temp = head;
    while (temp != NULL)
    {
        Node *copynode = new Node(temp->data);
        copynode->next = temp->next;
        temp->next = copynode;
        temp = temp->next->next;
    }

    // step 2 -> Connect Random Pointers
    temp = head;
    while (temp != NULL)
    {
        Node *copynode = temp->next;
        temp->random ? copynode->random = temp->random->next : copynode->random = NULL;
        temp = temp->next->next;
    }

    // step 3 -> Connect Next Pointers
    Node *dnode = new Node(-1);
    Node *res = dnode;
    temp = head;
    while (temp != NULL)
    {
        res->next = temp->next;
        temp->next = temp->next->next;
        res = res->next;
        temp = temp->next;
    }
    return dnode->next;
}