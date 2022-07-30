#include <iostream>
#include <queue>
#include <limits.h>
#include <vector>
#include "binaryTree.h"
#include "linkedClass.cpp"
using namespace std;

binaryTreeNode<int> *takeInput()
{
    cout << "enter root data" << endl;
    int rootData;
    cin >> rootData;
    if (rootData == -1)
    {
        return NULL;
    }
    queue<binaryTreeNode<int> *> pd;
    binaryTreeNode<int> *root = new binaryTreeNode<int>(rootData);
    pd.push(root);
    while (pd.size() != 0)
    {
        binaryTreeNode<int> *front = pd.front();
        pd.pop();
        cout << "enter left child of " << front->data << endl;
        int leftChild;
        cin >> leftChild;
        if (leftChild != -1)
        {
            binaryTreeNode<int> *left = new binaryTreeNode<int>(leftChild);
            front->left = left;
            pd.push(front->left);
        }
        cout << "enter right child of " << front->data << endl;
        int rightChild;
        cin >> rightChild;
        if (rightChild != -1)
        {
            binaryTreeNode<int> *right = new binaryTreeNode<int>(rightChild);
            front->right = right;
            pd.push(front->right);
        }
    }
    return root;
}

void printLevelWise(binaryTreeNode<int> *root)
{
    queue<binaryTreeNode<int> *> pd;
    pd.push(root);
    pd.push(NULL);
    while (pd.size() != 0)
    {
        binaryTreeNode<int> *front = pd.front();
        pd.pop();
        if (front == NULL)
        {
            if (pd.size() == 0)
            {
                break;
            }
            pd.push(NULL);
            cout << endl;
        }
        else
        {
            if (front->left)
            {
                pd.push(front->left);
            }
            if (front->right)
            {
                pd.push(front->right);
            }
            cout << front->data << " ";
        }
    }
}

void binarySearchTree(binaryTreeNode<int> *root, int n, bool &ans)
{
    if (root == NULL)
    {
        ans = false;
        return;
    }
    if (root->data == n)
    {
        ans = true;
        return;
    }
    if (root->data > n)
    {
        binarySearchTree(root->left, n, ans);
    }
    if (root->data < n)
    {
        binarySearchTree(root->right, n, ans);
    }
}

void printRangeWise(binaryTreeNode<int> *root, int x, int y)
{
    if (root == NULL)
    {
        return;
    }
    if (root->data > x)
    {
        printRangeWise(root->left, x, y);
    }
    if (root->data >= x && root->data <= y)
    {
        cout << root->data << ", ";
    }

    if (root->data < y)
    {
        printRangeWise(root->right, x, y);
    }
}

binaryTreeNode<int> *constructBinarySearchTree(int a[], int s, int e)
{
    if (s > e)
    {
        return NULL;
    }

    int mid = (s + e) / 2;

    binaryTreeNode<int> *root = new binaryTreeNode<int>(a[mid]);
    root->left = constructBinarySearchTree(a, s, mid - 1);
    root->right = constructBinarySearchTree(a, mid + 1, e);

    return root;
}

void displayLinkedList(node *head)
{
    while (head != NULL)
    {
        cout << head->data << " -> ";
        head = head->next;
    }
    cout << " NULL " << endl;
}

// pair<node *, node *> BSTtoLL(binaryTreeNode<int> *root)
// {
//     if (root == NULL)
//     {
//         pair<node *, node *> output;
//         output.first = NULL;
//         output.second = NULL;
//         return output;
//     }
//     node *head = new node(root->data);
//     pair<node *, node *> left = BSTtoLL(root->left);
//     pair<node *, node *> right = BSTtoLL(root->right);

//     left.second->next = head;
//     head->next = right.first;

//     pair<node *, node *> output;
//     output.first = left.first;
//     output.second = right.second;

//     return output;
// }

// node *BSTtoLL(binaryTreeNode<int> *root)
// {
//     if (root == NULL)
//     {
//         return NULL;
//     }
//     node *head = new node(root->data);
//     node *lhead = BSTtoLL(root->left);
//     node *rhead = BSTtoLL(root->right);

//     node *temp = lhead;
//     if (temp != NULL)
//     {

//         while (temp->next != NULL)
//         {
//             temp = temp->next;
//         }
//         temp->next = head;
//     }
//     head->next = rhead;

//     return head;
// }

vector<int> *getRootToPath(binaryTreeNode<int> *root, int data)
{
    if (root == NULL)
    {
        return NULL;
    }
    if (root->data == data)
    {
        vector<int> *output = new vector<int>();
        output->push_back(root->data);
        return output;
    }
    vector<int> *leftOutput = getRootToPath(root->left, data);

    if (leftOutput != NULL)
    {
        leftOutput->push_back(root->data);
        return leftOutput;
    }
    vector<int> *rightOutput = getRootToPath(root->right, data);
    if (rightOutput != NULL)
    {
        rightOutput->push_back(root->data);
        return rightOutput;
    }
    else
    {
        return NULL;
    }
}

int main()
{
    binaryTreeNode<int> *root = takeInput();
    int data;
    cin >> data;
    vector<int> *output = getRootToPath(root, data);
    for (int i = 0; i < output->size(); i++)
    {
        cout << output->at(i) << endl;
    }

    return 0;
}