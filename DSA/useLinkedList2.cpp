#include <iostream>
using namespace std;


class node
{
public:
    int data;
    node *next;

    node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

node *input()
{
    int data;
    cin >> data;
    node *head = NULL;
    node *tail = NULL;
    while (data != -1)
    {
        node *newNode = new node(data);
        if (head == NULL && tail == NULL)
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            tail->next = newNode;
            tail = newNode;
        }
        cin >> data;
    }
    return head;
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

// node *evenAfterOdd(node *head)
// {
//     node *temp = head;
//     node *head1 = new node(-1);
//     node *head2 = new node(-1);
//     node *temp1 = head1;
//     node *temp2 = head2;
//     while (temp != NULL)
//     {
//         node *newNode = new node(temp->data);
//         if (temp->data % 2 != 0)
//         {
//             temp1->next = newNode;
//             temp1 = temp1->next;
//         }
//         else
//         {
//             temp2->next = newNode;
//             temp2 = temp2->next;
//         }
//         temp = temp->next;
//     }
//     temp1->next = head2->next;
//     return head1->next;
// }

void deleteNNodes(node *&head, int M, int N) 
{
   node *current = head, *temp;
   int count;
   while (current) {
      // skip M nodes
      for (count = 1; count < M && current!= NULL; count++) {
         current = current->next;
      }
      // end of the linked list
      if (current == NULL) {
         return;
      }
      // deleting N nodes after M nodes
      temp = current->next;
      for (count = 1; count <= N && temp != NULL; count++) {
         node *deletingNode = temp;
         temp = temp->next;
         free(deletingNode);
      }
      current->next = temp;
      current = temp;
   }
}

int main()
{
    node *head1 = input();
    int m, n;
    cin >> m, n;
    deleteNNodes(head1, m, n);
    displayLinkedList(head1);
    return 0;
}