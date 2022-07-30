#include <iostream>
#include <queue>
#include <limits.h>
#include <vector>
#include "binaryTree.h"
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

int countNodes(binaryTreeNode<int> *root)
{
    if (root == NULL)
    {
        return 0;
    }
    int n = countNodes(root->left);
    int m = countNodes(root->right);
    return 1 + n + m;
}

bool findX(binaryTreeNode<int> *root, int x)
{
    if (root == NULL)
    {
        return false;
    }
    if (root->data == x)
    {
        return true;
    }
    bool left = findX(root->left, x);
    bool right = findX(root->right, x);

    if (left || right)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int height(binaryTreeNode<int> *root)
{
    if (root == NULL)
    {
        return 0;
    }
    int h1 = height(root->left);
    int h2 = height(root->right);

    int max1 = max(h1, h2);

    return 1 + max1;
}

void mirrorBinary(binaryTreeNode<int> *root)
{
    if (root == NULL)
    {
        return;
    }
    binaryTreeNode<int> *temp = root->left;
    root->left = root->right;
    root->right = temp;

    mirrorBinary(root->left);
    mirrorBinary(root->right);
}

void preorder(binaryTreeNode<int> *root)
{
    if (root == NULL)
    {
        return;
    }
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}
void postorder(binaryTreeNode<int> *root)
{
    if (root == NULL)
    {
        return;
    }
    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}
void inorder(binaryTreeNode<int> *root)
{
    if (root == NULL)
    {
        return;
    }
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

binaryTreeNode<int> *buildTree(int po[], int io[], int sop, int eop, int soi, int eoi)
{
    if (sop > eop)
    {
        return NULL;
    }
    int p = eop - sop + 1;
    int i = eoi - soi + 1;

    int n;

    for (int j = 0; j < i; j++)
    {
        if (po[sop] == io[j])
        {
            n = j;
            break;
        }
    }

    binaryTreeNode<int> *root = new binaryTreeNode<int>(po[sop]);
    root->left = buildTree(po, io, sop + 1, sop + n, soi, n - 1);
    root->right = buildTree(po, io, sop + n + 1, eop, n + 1, eoi);

    return root;
}

int diameter(binaryTreeNode<int> *root)
{
    if (root == NULL)
    {
        return 0;
    }
    int d = height(root->left) + height(root->right);
    int d1 = diameter(root->left);
    int d2 = diameter(root->right);

    return max(d, max(d1, d2));
}

pair<int, int> diameterP(binaryTreeNode<int> *root)
{
    if (root == NULL)
    {
        pair<int, int> p;
        p.first = 0;
        p.second = 0;
        return p;
    }
    pair<int, int> leftans = diameterP(root->left);
    pair<int, int> rightans = diameterP(root->right);

    int lh = leftans.first;
    int ld = leftans.second;
    int rh = rightans.first;
    int rd = rightans.second;

    int height = 1 + max(lh, rh);
    int diameter = max(lh + rh, max(ld, rd));

    pair<int, int> p;
    p.first = height;
    p.second = diameter;

    return p;
}

pair<int, int> maxmin(binaryTreeNode<int> *root)
{
    if (root == NULL)
    {
        pair<int, int> p;
        p.first = 0;
        p.second = INT_MAX;
        return p;
    }

    pair<int, int> leftTree = maxmin(root->left);
    pair<int, int> rightTree = maxmin(root->right);

    int lmax = leftTree.first;
    int lmin = leftTree.second;
    int rmax = rightTree.first;
    int rmin = rightTree.second;

    int max1 = max(root->data, max(lmax, rmax));
    int min1 = min(root->data, min(lmin, rmin));

    pair<int, int> p;
    p.first = max1;
    p.second = min1;

    return p;
}

int sum(binaryTreeNode<int> *root)
{
    if (root == NULL)
    {
        return 0;
    }
    int sumL = sum(root->left);
    int sumR = sum(root->right);

    return root->data + sumL + sumR;
}

bool balance(binaryTreeNode<int> *root)
{
    if (root == NULL)
    {
        return true;
    }
    int h1 = height(root->left);
    int h2 = height(root->right);
    if (h1 - h2 >= 1 || h2 - h1 >= 1)
    {
        return false;
    }
    bool leftTree = balance(root->left);
    bool rightTree = balance(root->right);

    if (leftTree && rightTree)
    {
        return true;
    }
    return false;
}

pair<int, bool> balanceTree(binaryTreeNode<int> *root)
{
    if (root == NULL)
    {
        pair<int, bool> p;
        p.first = 0;
        p.second = true;
        return p;
    }
    pair<int, bool> leftTree = balanceTree(root->left);
    pair<int, bool> rightTree = balanceTree(root->right);

    int lh = leftTree.first;
    int rh = rightTree.first;
    bool lbal = (rh - lh <= 1 || lh - rh <= 1);
    bool rbal = (rh - lh <= 1 || lh - rh <= 1);

    pair<int, bool> p;
    p.first = 1 + max(lh, rh);
    p.second = (lbal && rbal);

    return p;
}

binaryTreeNode<int> *removeLeafNode(binaryTreeNode<int> *root)
{
    if (root == NULL)
    {
        return NULL;
    }
    if (root->left == NULL && root->right == NULL)
    {
        return NULL;
    }

    binaryTreeNode<int> *left = removeLeafNode(root->left);
    binaryTreeNode<int> *right = removeLeafNode(root->right);

    root->left = left;
    root->right = right;

    return root;
}

class node
{
public:
    int data;
    node *next;

    node(int data)
    {
        this->data = data;
        next = NULL;
    }
};

void printSiblings(binaryTreeNode<int> *root)
{
    if (root == NULL)
    {
        return;
    }
    if (root->left == NULL && root->right != NULL)
    {
        cout << root->right->data << " ";
    }
    if (root->right == NULL && root->left != NULL)
    {
        cout << root->left->data << " ";
    }
    printSiblings(root->left);
    printSiblings(root->right);
}

int main()
{
    binaryTreeNode<int> *root = takeInput();
    printSiblings(root);
}