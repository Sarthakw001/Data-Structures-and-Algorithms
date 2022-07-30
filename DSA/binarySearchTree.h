#include <iostream>
#include "binaryTree.h"
using namespace std;
class BST
{
    binaryTreeNode<int> *root;
public:
    BST()
    {
        root = NULL;
    }
    ~BST()
    {
        delete root;
    }

    // bool hasData(int data, binaryTreeNode<int> *node)
    // {
    //     if (node == NULL)
    //     {
    //         return false;
    //     }
    //     if (node->data == data)
    //     {
    //         return true;
    //     }
    //     else if (data < node->data)
    //     {
    //         return hasData(data, root->left);
    //     }
    //     else
    //     {
    //         return hasData(data, root->right);
    //     }
    // }
    binaryTreeNode<int> *insert(int data, binaryTreeNode<int> *node)
    {
        if (node == NULL)
        {
            binaryTreeNode<int> *newNode = new binaryTreeNode<int>(data);
            return newNode;
        }
        if (data < node->data)
        {
            node->left = insert(data, root->left);
        }
        else
        {
            node->right = insert(data, root->right);
        }
        return node;
    }
    void printBST(binaryTreeNode<int> *node)
    {
        if (root == NULL)
        {
            return;
        }
        cout << root->data << ":";
        if (root->left != NULL)
        {
            cout << "L" << root->left->data << " ";
        }
        if (root->right != NULL)
        {
            cout << "R" << root->right->data << " " << endl;
        }
        printBST(root->left);
        printBST(root->right);
    }


    void insert(int data)
    {
        this->root = insert(data, this->root);
    }
    // bool hasData(int data)
    // {
    //     return hasData(data, root);
    // }
    void printBST()
    {
        printBST(root);
    }
};