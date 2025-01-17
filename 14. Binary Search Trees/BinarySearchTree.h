#include "BinaryTreeNode.h"
#include <bits/stdc++.h>
using namespace std;
class BST
{
public:
    BinaryTreeNode<int> *root;

private:
    bool search(BinaryTreeNode<int> *root, int data)
    {
        if (root == NULL)
            return false;
        if (root->data == data)
            return true;
        if (data > root->data)
            return search(root->right, data);
        if (data < root->data)
            return search(root->left, data);
    }
    BinaryTreeNode<int> *insert(BinaryTreeNode<int> *node, int data)
    {
        if (node == NULL)
        {
            BinaryTreeNode<int> *node = new BinaryTreeNode<int>(data);
            return node;
        }
        if (data > node->data)
            node->right = insert(node->right, data);
        else
            node->left = insert(node->left, data);
        return node;
    }
    BinaryTreeNode<int> *findMin(BinaryTreeNode<int> *node)
    {
        if (node->left == NULL)
            return node;
        return findMin(node->left);
    }
    BinaryTreeNode<int> *findMax(BinaryTreeNode<int> *node)
    {
        if (node->right == NULL)
            return node;
        return findMax(node->right);
    }
    BinaryTreeNode<int> *remove(BinaryTreeNode<int> *node, int data)
    {
        if (node == NULL)
            return NULL;
        if (data > node->data)
            node->right = remove(node->right, data);
        else if (data < node->data)
            node->left = remove(node->left, data);
        else
        {
            if (node->left == NULL && node->right == NULL)
            {
                delete node;
                return NULL;
            }
            else if (node->left == NULL)
            {
                BinaryTreeNode<int> *temp = node->right;
                node->right = NULL;
                delete node;
                return temp;
            }
            else if (node->right == NULL)
            {
                BinaryTreeNode<int> *temp = node->left;
                node->left = NULL;
                delete node;
                return temp;
            }
            else
            {
                BinaryTreeNode<int> *minnode = findMin(node->right);
                node->data = minnode->data;
                node->right = remove(node->right, minnode->data);
                return node;
            }
        }
        return node;
    }
    void printTree(BinaryTreeNode<int> *node)
    {
        if (node == NULL)
            return;
        cout << node->data << ":";
        if (node->left != NULL)
            cout << "L:" << node->left->data << ",";
        if (node->right != NULL)
            cout << "R:" << node->right->data;
        cout << endl;
        printTree(node->left);
        printTree(node->right);
    }
public:
    BST()
    {
        root = NULL;
    }
    ~BST()
    {
        delete root;
    }
    void insert(int data) { this->root = insert(this->root, data); }
    void remove(int data) { this->root = remove(this->root, data); }
    bool search(int data) { return search(this->root, data); }
    void print() { printTree(root); }
};