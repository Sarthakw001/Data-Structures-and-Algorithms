#include<iostream>
#include"binarySearchTree.h"
using namespace std;

int main()
{
    BST b;
    b.insert(10);
    b.insert(5);
    b.insert(20);
    b.insert(3);
    b.insert(56);
    b.printBST();
}