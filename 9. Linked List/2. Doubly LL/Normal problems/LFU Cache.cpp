#include <bits/stdc++.h>
using namespace std;

class LFUCache
{
public:
    class Node
    {
    public:
        int key;
        int val;
        int cnt;
        Node *next;
        Node *prev;
        Node(int key, int val)
        {
            this->key = key;
            this->val = val;
            this->cnt = 1;
        }
    };

    class List
    {
    public:
        Node *head;
        Node *tail;
        List()
        {
            head = new Node(-1, -1);
            tail = new Node(-1, -1);
            head->next = tail;
            tail->prev = head;
        }
    };

    Node *head = new Node(-1, -1);
    Node *tail = new Node(-1, -1);
    int size;
    int minCount;
    unordered_map<int, Node *> keyNodeMap;
    unordered_map<int, List *> countListMap;

    LFUCache(int capacity)
    {
        size = capacity;
    }
    void addNode(Node *head, Node *newnode)
    {
        Node *temp = head->next;
        head->next = newnode;
        newnode->prev = head;

        temp->prev = newnode;
        newnode->next = temp;
    }

    void deleteNode(Node *delnode)
    {
        Node *nextt = delnode->next;
        Node *prevv = delnode->prev;

        prevv->next = nextt;
        nextt->prev = prevv;
    }
    int get(int key)
    {
        if (keyNodeMap.find(key) == keyNodeMap.end())
            return -1;
        else
        {
            Node *resNode = keyNodeMap[key];
            deleteNode(resNode);
            if (resNode->cnt == minCount && countListMap[resNode->cnt]->head->next == countListMap[resNode->cnt]->tail)
                minCount++;
            resNode->cnt++;
            if (countListMap.find(resNode->cnt) == countListMap.end())
            {
                List *newList = new List;
                countListMap[resNode->cnt] = newList;
            }
            addNode(countListMap[resNode->cnt]->head, resNode);
            return resNode->val;
        }
    }

    void put(int key, int value)
    {
        if (keyNodeMap.find(key) != keyNodeMap.end())
        {
            keyNodeMap[key]->val = value;
            get(key);
        }
        else
        {
            if (keyNodeMap.size() == size)
            {
                Node *delNode = countListMap[minCount]->tail->prev;
                keyNodeMap.erase(delNode->key);
                deleteNode(delNode);
            }
            Node *newNode = new Node(key, value);
            keyNodeMap[key] = newNode;
            if (countListMap.find(newNode->cnt) == countListMap.end())
            {
                List *newList = new List;
                countListMap[newNode->cnt] = newList;
            }
            addNode(countListMap[newNode->cnt]->head, newNode);
            minCount = 1;
        }
    }
};
