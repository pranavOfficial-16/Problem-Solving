#include <bits/stdc++.h>
#include "TreeNode.h"
using namespace std;
TreeNode<int> *takeInputLevelWise()
{
    int rootData;
    cout << "Enter rootdata : " << endl;
    cin >> rootData;
    TreeNode<int> *root = new TreeNode<int>(rootData);
    queue<TreeNode<int> *> pendingNodes;
    pendingNodes.push(root);
    while (pendingNodes.size())
    {
        TreeNode<int> *front = pendingNodes.front();
        pendingNodes.pop();
        cout << "Enter number of children of " << front->data << endl;
        int numchild;
        cin >> numchild;
        for (int i = 0; i < numchild; i++)
        {
            int childData;
            cout << "Enter " << i << " th child of " << front->data << endl;
            cin >> childData;
            TreeNode<int> *child = new TreeNode<int>(childData);
            front->children.push_back(child);
            pendingNodes.push(child);
        }
    }
    return root;
}

void printTreeLevelWise(TreeNode<int> *root)
{
    if (root == NULL)
        return;
    queue<TreeNode<int> *> pendingNodes;
    pendingNodes.push(root);
    while (pendingNodes.size())
    {
        TreeNode<int> *front = pendingNodes.front();
        pendingNodes.pop();
        cout << front->data << ":";
        for (int i = 0; i < front->children.size(); i++)
        {
            cout << front->children[i]->data;
            if (i + 1 != front->children.size())
                cout << ",";
            pendingNodes.push(front->children[i]);
        }
        cout << endl;
    }
}
int numNodes(TreeNode<int> *root)
{
    if (root == NULL)
        return 0;
    int ans = 1;
    for (int i = 0; i < root->children.size(); i++)
    {
        ans += numNodes(root->children[i]);
    }
    return ans;
}
int sumOfNodes(TreeNode<int> *root)
{
    if (root == NULL)
        return 0;
    int sum = root->data;
    for (int i = 0; i < root->children.size(); i++)
    {
        sum += sumOfNodes(root->children[i]);
    }
    return sum;
}
TreeNode<int> *maxDataNode(TreeNode<int> *root)
{
    if (root == NULL)
        return root;
    TreeNode<int> *max = new TreeNode<int>(root->data);
    for (int i = 0; i < root->children.size(); i++)
    {
        TreeNode<int> *child = maxDataNode(root->children[i]);
        if (child->data > max->data)
            max = child;
    }
    return max;
}
TreeNode<int> *minDataNode(TreeNode<int> *root)
{
    if (root == NULL)
        return root;
    TreeNode<int> *min = new TreeNode<int>(root->data);
    for (int i = 0; i < root->children.size(); i++)
    {
        TreeNode<int> *child = maxDataNode(root->children[i]);
        if (child->data < min->data)
            min = child;
    }
    return min;
}
int getHeight(TreeNode<int> *root)
{
    int temp = 0, height = 0;
    if (root == NULL)
        return 0;
    if (root->children.size() == 0)
        return 1;
    for (int i = 0; i < root->children.size(); i++)
    {
        temp = getHeight(root->children[i]);
        if (temp > height)
            height = temp;
    }
    return height + 1;
}
void printAtLevelK(TreeNode<int> *root, int k)
{
    if (root == NULL)
        return;
    if (k == 0)
    {
        cout << root->data << endl;
        return;
    }
    for (int i = 0; i < root->children.size(); i++)
        printAtLevelK(root->children[i], k - 1);
}
int getLeafNodeCount(TreeNode<int> *root)
{
    if (root->children.size() == 0)
        return 1;
    int ans = 0;
    for (int i = 0; i < root->children.size(); i++)
        ans += getLeafNodeCount(root->children[i]);
    return ans;
}
void printPreOrder(TreeNode<int> *root)
{
    if (root == NULL)
        return;
    cout << root->data << " ";
    for (int i = 0; i < root->children.size(); i++)
        printPreOrder(root->children[i]);
}
void printPostOrder(TreeNode<int> *root)
{
    if (root == NULL)
        return;
    for (int i = 0; i < root->children.size(); i++)
        printPostOrder(root->children[i]);
    cout << root->data << " ";
}
// Deletion of the tree is post order traversal fashion
void deleteTree(TreeNode<int> *root)
{
    if (root == NULL)
        return;
    for (int i = 0; i < root->children.size(); i++)
        deleteTree(root->children[i]);
    delete root;
}
// Check if the tree contains x
bool isPresent(TreeNode<int> *root, int x)
{
    if (root->data == x)
        return true;
    for (int i = 0; i < root->children.size(); i++)
        if (isPresent(root->children[i], x))
            return true;
    return false;
}
// count nodes greater than x
int getLargeNodeCount(TreeNode<int> *root, int x)
{
    int count = 0;
    if (root->data > x)
        count++;
    for (int i = 0; i < root->children.size(); i++)
        count += getLargeNodeCount(root->children[i], x);
    return count;
}
int sumNode(TreeNode<int> *root)
{
    int sum = root->data;
    for (int i = 0; i < root->children.size(); i++)
        sum += root->children[i]->data;
    return sum;
}
// node with maximum sum
TreeNode<int> *maxSumNode(TreeNode<int> *root)
{
    TreeNode<int> *result = root;
    int maxSum = sumNode(root);
    for (int i = 0; i < root->children.size(); i++)
    {
        TreeNode<int> *temp = maxSumNode(root->children[i]);
        int sum = sumNode(temp);
        if (sum > maxSum)
        {
            maxSum = sum;
            result = temp;
        }
    }
    return result;
}
// check if two trees are identical
bool areIdentical(TreeNode<int> *root1, TreeNode<int> *root2)
{
    if (root1->data != root2->data)
        return false;
    if (root1->children.size() != root2->children.size())
        return false;
    for (int i = 0; i < root1->children.size(); i++)
        if (!areIdentical(root1->children[i], root2->children[i]))
            return false;
    return true;
}
// get next larger element
TreeNode<int> *getNextLargerElement(TreeNode<int> *root, int x)
{
    int childCount = root->children.size();
    TreeNode<int> *result = NULL;
    if (root->data > x)
        result = root;
    for (int i = 0; i < childCount; i++)
    {
        TreeNode<int> *temp = getNextLargerElement(root->children[i], x);
        if (result == NULL || result->data > temp->data)
            result = temp;
    }
    return result;
}

// Replace with depth value i.e.. 0 1 2
void replaceDepth(TreeNode<int> *root, int value)
{
    root->data = value;
    for (int i = 0; i < root->children.size(); i++)
        replaceDepth(root->children[i], value + 1);
}
void replaceWithDepthValue(TreeNode<int> *root)
{
    replaceDepth(root, 0);
}

// get second largest node
void getsecondmax(TreeNode<int> *root, TreeNode<int> **first, TreeNode<int> **second)
{

    if (!(*first))
        *first = root;
    else if (root->data > (*first)->data)
    {
        *second = *first;
        *first = root;
    }
    else if (!(*second))
    {
        if (root->data < (*first)->data)
            *second = root;
    }
    else if (root->data < (*first)->data && root->data > (*second)->data)
        *second = root;

    int numChildren = root->children.size();

    for (int i = 0; i < numChildren; i++)
        getsecondmax(root->children[i], first, second);
}
TreeNode<int> *getSecondLargestNode(TreeNode<int> *root)
{
    TreeNode<int> *first = NULL;
    TreeNode<int> *second = NULL;
    getsecondmax(root, &first, &second);
    return second;
}
// Remove leaf nodes in Tree
// TreeNode<int> *removeLeafNodes(TreeNode<int> *root)
// {
//     if (root == NULL)
//         return NULL;
//     if (root->numChildren() == 0)
//     {
//         delete root;
//         return NULL;
//     }
//     for (int i = 0; i < root->numChildren(); i++)
//     {
//         TreeNode<int> *child = root->getChild(i);
//         if (child->numChildren() == 0)
//         {
//             root->removeChild(i);
//             i--;
//         }
//         else
//             root->setChild(i, removeLeafNodes(child));
//     }
//     return root;
// }

// 1 3 2 3 4 2 5 6 1 7 1 8 0 0 1 9 0 0
int main()
{
    TreeNode<int> *root = takeInputLevelWise();
    printTreeLevelWise(root);
    cout << "No of nodes : " << numNodes(root) << endl;
    cout << "Sum of nodes : " << sumOfNodes(root) << endl;
    TreeNode<int> *max = maxDataNode(root);
    cout << "Max data node : " << max->data << endl;
    TreeNode<int> *min = minDataNode(root);
    cout << "Min data node : " << min->data << endl;
    cout << "Height of the tree : " << getHeight(root) << endl;
    int k = 2;
    cout << "Nodes at level " << k << " is " << endl;
    printAtLevelK(root, k);
    cout << "No of leaf nodes i.e.. no child : " << getLeafNodeCount(root) << endl;
    cout << "Pre-order Traversal tree is" << endl;
    printPreOrder(root);
    cout << endl;
    cout << "Post-order Traversal tree is" << endl;
    printPostOrder(root);
    cout << endl;
    cout << isPresent(root, 4) << endl;
    cout << getLargeNodeCount(root, 6) << endl;
    TreeNode<int> *result = maxSumNode(root);
    cout << "Node with max sum : " << result->data << endl;
    // deleteTree(root); manually deletion of tree
    delete root; // calls the destructor (better approach)
    return 0;
}