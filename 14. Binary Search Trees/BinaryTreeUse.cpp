#include <bits/stdc++.h>
#include "BinaryTreeNode.h"
using namespace std;
BinaryTreeNode<int> *takeInputLevelWise()
{
    int rootData;
    cout << "Enter rootdata : " << endl;
    cin >> rootData;
    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(rootData);
    queue<BinaryTreeNode<int> *> pendingNodes;
    pendingNodes.push(root);
    while (pendingNodes.size())
    {
        BinaryTreeNode<int> *front = pendingNodes.front();
        pendingNodes.pop();
        cout << "Enter left child of " << front->data << endl;
        int leftChildData;
        cin >> leftChildData;
        if (leftChildData != -1)
        {
            BinaryTreeNode<int> *child = new BinaryTreeNode<int>(leftChildData);
            front->left = child;
            pendingNodes.push(child);
        }
        cout << "Enter Right child of " << front->data << endl;
        int rightChildData;
        cin >> rightChildData;
        if (rightChildData != -1)
        {
            BinaryTreeNode<int> *child = new BinaryTreeNode<int>(rightChildData);
            front->right = child;
            pendingNodes.push(child);
        }
    }
    return root;
}
void printLevelWise(BinaryTreeNode<int> *root)
{
    if (root == NULL)
        return;
    queue<BinaryTreeNode<int> *> pendingNodes;
    pendingNodes.push(root);
    while (pendingNodes.size())
    {
        BinaryTreeNode<int> *front = pendingNodes.front();
        pendingNodes.pop();
        cout << front->data << ":";
        if (front->left)
        {
            pendingNodes.push(front->left);
            cout << "L:" << front->left->data;
        }
        else
            cout << "L:-1";
        cout << ",";
        if (front->right)
        {
            pendingNodes.push(front->right);
            cout << "R:" << front->right->data;
        }
        else
            cout << "R:-1";
        cout << endl;
    }
}
// Search in BST
bool searchInBST(BinaryTreeNode<int> *root, int k)
{
    if (root == NULL)
        return false;
    if (root->data == k)
        return true;
    if (k > root->data)
        return searchInBST(root->right, k);
    if (k < root->data)
        return searchInBST(root->left, k);
}
// Print Elements in Range
void elementsInRangeK1K2(BinaryTreeNode<int> *root, int k1, int k2)
{
    if (root == NULL)
        return;
    if (k1 < root->data)
        elementsInRangeK1K2(root->left, k1, k2);
    if (root->data >= k1 && root->data <= k2)
        cout << root->data << " ";
    if (k2 > root->data)
        elementsInRangeK1K2(root->right, k1, k2);
}
// Check if a Binary Tree is BST
// approach 1
class Pair
{
public:
    int minimum;
    int maximum;
    bool check;
};
Pair solve(BinaryTreeNode<int> *root)
{
    if (root == NULL)
    {
        Pair p;
        p.minimum = INT_MAX;
        p.maximum = INT_MIN;
        p.check = true;
        return p;
    }
    Pair left = solve(root->left);
    Pair right = solve(root->right);
    Pair p;
    p.minimum = min(root->data, left.minimum);
    p.maximum = max(root->data, right.maximum);
    p.check = (root->data > left.maximum) && (root->data < right.minimum) && left.check && right.check;
    return p;
}
bool isBST(BinaryTreeNode<int> *root)
{
    return solve(root).check;
}

// Check if a Binary Tree is BST
// approach 2
BinaryTreeNode<int> *findMin(BinaryTreeNode<int> *node)
{
    if (node == NULL)
        return NULL;
    if (node->left == NULL)
        return node;
    return findMin(node->left);
}
BinaryTreeNode<int> *findMax(BinaryTreeNode<int> *node)
{
    if (node == NULL)
        return NULL;
    if (node->right == NULL)
        return node;
    return findMax(node->right);
}
bool isValidBST(BinaryTreeNode<int> *root)
{
    if (root == NULL)
        return true;
    BinaryTreeNode<int> *leftmax = findMax(root->left);
    BinaryTreeNode<int> *rightmin = findMin(root->right);

    if ((leftmax && root->data <= leftmax->data) ||
        (rightmin && root->data >= rightmin->data))
        return false;

    return isValidBST(root->left) && isValidBST(root->right);
}

// Construct BST from a Sorted Array
BinaryTreeNode<int> *solve(int *arr, int start, int end)
{
    if (start > end)
        return NULL;
    int mid = (start + end) / 2;
    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(arr[mid]);
    root->left = solve(arr, start, mid - 1);
    root->right = solve(arr, mid + 1, end);
    return root;
}
BinaryTreeNode<int> *constructTree(int *arr, int n)
{
    return solve(arr, 0, n - 1);
}
// Inorder traversal
void inorder(BinaryTreeNode<int> *root)
{
    if (root == NULL)
        return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}
//  BST to Sorted LL
template <typename T>
class Node
{
public:
    T data;
    Node *next;
    Node(T data)
    {
        this->data = data;
        next = NULL;
    }
};
void solve(vector<int> &v, BinaryTreeNode<int> *root)
{
    if (root == NULL)
        return;
    solve(v, root->left);
    v.push_back(root->data);
    solve(v, root->right);
}
Node<int> *constructLinkedList(BinaryTreeNode<int> *root)
{
    vector<int> v;
    solve(v, root);
    Node<int> *head = NULL;
    Node<int> *tail = NULL;
    for (int i : v)
    {
        Node<int> *newnode = new Node<int>(i);
        if (head == NULL)
        {
            head = newnode;
            tail = newnode;
        }
        else
        {
            tail->next = newnode;
            tail = newnode;
        }
    }
    return head;
}

// Find Path in BST
vector<int> *getPath(BinaryTreeNode<int> *root, int data)
{
    if (root == NULL)
        return NULL;

    if (root->data == data)
    {
        vector<int> *output = new vector<int>();
        output->push_back(root->data);
        return output;
    }

    vector<int> *leftOutput = getPath(root->left, data);
    if (leftOutput != NULL)
    {
        leftOutput->push_back(root->data);
        return leftOutput;
    }

    vector<int> *rightOutput = getPath(root->right, data);
    if (rightOutput != NULL)
    {
        rightOutput->push_back(root->data);
        return rightOutput;
    }
    else
        return NULL;
}

// Largest BST
struct LargestBST
{
    int minimum;
    int maximum;
    int height;
    bool isBST;
};

LargestBST verify(BinaryTreeNode<int> *root)
{
    if (root == NULL)
    {
        return {INT_MAX, INT_MIN, 0, true};
    }

    LargestBST left = verify(root->left);
    LargestBST right = verify(root->right);

    if (left.isBST && right.isBST && root->data > left.maximum && root->data < right.minimum)
    {
        return {
            min(left.minimum, root->data),
            max(right.maximum, root->data),
            left.height + right.height + 1,
            true};
    }

    return {
        0,
        0,
        max(left.height, right.height),
        false};
}
class Solution
{
public:
    int largestBst(BinaryTreeNode<int> *root)
    {
        return verify(root).height;
    }
};

// Replace with Sum of greater nodes
int solve(BinaryTreeNode<int> *root, int sum)
{
    if (root == NULL)
        return sum;
    sum = solve(root->right, sum);
    sum += root->data;
    root->data = sum;
    sum = solve(root->left, sum);
    return sum;
}
void replaceWithLargerNodesSum(BinaryTreeNode<int> *root)
{
    if (root == NULL)
        return;
    int ans = solve(root, 0);
}

// Ceil in BST
int findCeil(BinaryTreeNode<int> *root, int input)
{
    int ceil = -1;
    while (root)
    {

        if (input == root->data)
        {
            ceil = root->data;
            return ceil;
        }
        else if (input > root->data)
            root = root->right;
        else
        {
            ceil = root->data;
            root = root->left;
        }
    }
    return ceil;
}

// Floor in BST
int floor(BinaryTreeNode<int> *root, int k)
{
    int floor = -1;
    while (root)
    {
        if (k == root->data)
        {
            floor = root->data;
            return floor;
        }
        else if (k > root->data)
        {
            floor = root->data;
            root = root->right;
        }
        else
            root = root->left;
    }
    return floor;
}

// kth smallest
int kthSmallest(BinaryTreeNode<int> *root, int k)
{
    BinaryTreeNode<int> *current = root;
    stack<BinaryTreeNode<int> *> stack;
    int count = 0;

    while (!stack.empty() || current != NULL)
    {
        while (current != NULL)
        {
            stack.push(current);
            current = current->left;
        }

        current = stack.top();
        stack.pop();
        count++;

        if (count == k)
            return current->data;
        current = current->right;
    }
    return -1;
}

// kth largest
int kthLargest(BinaryTreeNode<int> *root, int k)
{
    stack<BinaryTreeNode<int> *> stack;
    BinaryTreeNode<int> *current = root;
    int count = 0;

    while (!stack.empty() || current != NULL)
    {
        while (current != NULL)
        {
            stack.push(current);
            current = current->right;
        }

        current = stack.top();
        stack.pop();

        count++;
        if (count == k)
            return current->data;

        current = current->left;
    }
    return -1;
}

//  LCA of BST
BinaryTreeNode<int> *lowestCommonAncestor(BinaryTreeNode<int> *root, BinaryTreeNode<int> *p, BinaryTreeNode<int> *q)
{
    if (root == NULL || root == p || root == q)
        return root;
    if (p->data < root->data && q->data < root->data)
        return lowestCommonAncestor(root->left, p, q);
    if (p->data > root->data && q->data > root->data)
        return lowestCommonAncestor(root->right, p, q);
    return root;
}

// Construct Binary Search Tree from Preorder Traversal
BinaryTreeNode<int> *solve(vector<int> &preorder, int &index, int lb, int ub)
{
    if (index >= preorder.size() || preorder[index] < lb || preorder[index] > ub)
        return NULL;

    int value = preorder[index++];
    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(value);

    root->left = solve(preorder, index, lb, value);
    root->right = solve(preorder, index, value, ub);
    return root;
}
BinaryTreeNode<int> *bstFromPreorder(vector<int> &preorder)
{
    int index = 0;
    return solve(preorder, index, INT_MIN, INT_MAX);
}

// Inorder Successor in BST
BinaryTreeNode<int> *inorderSuccessor(BinaryTreeNode<int> *root, BinaryTreeNode<int> *p)
{

    BinaryTreeNode<int> *successor = NULL;
    while (root != NULL)
    {
        if (root->data <= p->data)
            root = root->right;
        else
        {
            successor = root;
            root = root->left;
        }
    }
    return successor;
}

// Inorder Predecessor in BST
BinaryTreeNode<int> *inorderPredecessor(BinaryTreeNode<int> *root, BinaryTreeNode<int> *p)
{

    BinaryTreeNode<int> *predecessor = NULL;
    while (root != NULL)
    {
        if (root->data >= p->data)
            root = root->left;
        else
        {
            predecessor = root;
            root = root->right;
        }
    }
    return predecessor;
}

// Binary Search Tree Iterator
class BSTIterator
{
public:
    stack<BinaryTreeNode<int> *> myStack;
    void pushAll(BinaryTreeNode<int> *root)
    {
        while (root != NULL)
        {
            myStack.push(root);
            root = root->left;
        }
    }

    BSTIterator(BinaryTreeNode<int> *root)
    {
        pushAll(root);
    }

    int next()
    {
        BinaryTreeNode<int> *temp = myStack.top();
        myStack.pop();
        pushAll(temp->right);
        return temp->data;
    }

    bool hasNext()
    {
        return !myStack.empty();
    }
};

// Two Sum In BST
class BSTIterator
{
public:
    stack<BinaryTreeNode<int> *> myStack;
    bool reverse = true; // true->before, false->next
    void pushAll(BinaryTreeNode<int> *root)
    {
        while (root != NULL)
        {
            myStack.push(root);
            if (reverse == true)
                root = root->right;
            else
                root = root->left;
        }
    }

    BSTIterator(BinaryTreeNode<int> *root, bool isReverse)
    {
        reverse = isReverse;
        pushAll(root);
    }

    int next()
    {
        BinaryTreeNode<int> *temp = myStack.top();
        myStack.pop();
        if (!reverse)
            pushAll(temp->right);
        else
            pushAll(temp->left);
        return temp->data;
    }

    bool hasNext()
    {
        return !myStack.empty();
    }
};
class Solution
{
public:
    bool findTarget(BinaryTreeNode<int> *root, int k)
    {
        if (root == NULL)
            return false;
        BSTIterator l(root, false);
        BSTIterator r(root, true);

        int i = l.next();
        int j = r.next();
        while (i < j)
        {
            if (i + j == k)
                return true;
            else if (i + j < k)
                i = l.next();
            else
                j = r.next();
        }
        return false;
    }
};

// Recover Binary Search Tree
class Solution
{
public:
    BinaryTreeNode<int> *first = nullptr;
    BinaryTreeNode<int> *second = nullptr;
    BinaryTreeNode<int> *prev = nullptr;

    void inorder(BinaryTreeNode<int> *root)
    {
        if (!root)
            return;

        inorder(root->left);

        if (prev && root->data < prev->data)
        {
            if (!first)
            {
                first = prev;
            }
            second = root;
        }
        prev = root;

        inorder(root->right);
    }

    void recoverTree(BinaryTreeNode<int> *root)
    {
        inorder(root);

        if (first && second)
        {
            swap(first->data, second->data);
        }
    }
};