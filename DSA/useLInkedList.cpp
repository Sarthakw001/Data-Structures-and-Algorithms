#include <iostream>
using namespace std;
#include "linkedClass.cpp"

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

node *insertNode(node *head, int i, int data)
{
    node *newNode = new node(data);
    if (i == 0)
    {
        newNode->next = head;
        head = newNode;
        return head;
    }
    node *temp = head;
    int count = 0;
    while (temp != NULL && count < i - 1)
    {
        temp = temp->next;
        count++;
    }
    if (temp != NULL)
    {
        newNode->next = temp->next;
        temp->next = newNode;
    }
    return head;
}
node *deleteNode(node *head, int i)
{
    if (i == 0)
    {
        node *newHead = head->next;
        delete head;
        head = NULL;
        return newHead;
    }
    node *temp = head;
    int count = 0;
    while (temp != NULL && count < i - 1)
    {
        temp = temp->next;
        count++;
    }
    if (temp != NULL)
    {
        node *temp1 = temp->next;
        temp->next = temp->next->next;
        delete temp1;
        temp1 = NULL;
    }
    return head;
}
int lengthLinkedList(node *head)
{
    if (head == NULL)
    {
        return 0;
    }
    int s = lengthLinkedList(head->next);
    return 1 + s;
}

node *insertNodeRecursively(node *head, int i, int data)
{
    if (head == NULL)
    {
        return head;
    }
    if (i == 0)
    {
        node *newHead = new node(data);
        newHead->next = head;
        head = newHead;
        return head;
    }
    node *smallHead = insertNodeRecursively(head->next, i - 1, data);
    head->next = smallHead;
    return head;
}

node *deleteNodeRecursively(node *head, int i)
{
    if (head == NULL)
    {
        return head;
    }
    if (i == 0)
    {
        node *temp = head;
        head = head->next;
        delete temp;
        return head;
    }
    node *smallHead = deleteNodeRecursively(head->next, i - 1);
    head->next = smallHead;
    return head;
}

int linearSearch(node *head, int val)
{
    if (head == NULL)
    {
        return -1;
    }
    if (head->data != val)
    {
        int s = linearSearch(head->next, val);
        return 1 + s;
    }
    else
    {
        return 0;
    }
    return -1;
}

node *appendLastNnode(node *head, int n)
{
    node *temp = head;
    int count = 0;
    while (temp != NULL)
    {
        temp = temp->next;
        count++;
    }
    temp = head;
    int i = 1;
    while (i < (count - n))
    {
        temp = temp->next;
        i++;
    }
    node *head2 = temp->next;
    temp->next = NULL;
    node *temp1 = head2;
    while (temp1->next != NULL)
    {
        temp1 = temp1->next;
    }
    temp1->next = head;

    return head2;
}
void removeDuplicates(node *head)
{
    if (head == NULL)
    {
        return;
    }
    node *temp;

    if (head->next != NULL)
    {
        if (head->data == head->next->data)
        {

            head->next = head->next->next;

            removeDuplicates(head);
        }
        else
        {
            removeDuplicates(head->next);
        }
    }
}

node *reverse(node *head)
{

    if (head == NULL || head->next == NULL)
    {
        return head;
    }

    node *newHead = reverse(head->next);
    head->next->next = head;
    head->next = NULL;
    return newHead;
}

void reverseII(node *head)
{
    if (head == NULL)
    {
        return;
    }
    reverse(head->next);
    cout << head->data << "->";
}

bool palindrome(node *head)
{
    node *temp = head;
    node *newHead = NULL;
    node *newTail = NULL;
    while (temp != NULL)
    {
        node *newNode = new node(temp->data);
        if (newHead == NULL)
        {
            newHead = newNode;
            newTail = newNode;
        }
        else
        {
            newTail->next = newNode;
            newTail = newNode;
        }
        temp = temp->next;
    }
    newHead = reverse(newHead);
    temp = head;
    int count = 0;
    while (temp != NULL)
    {
        temp = temp->next;
        count++;
    }
    temp = head;
    bool ans[count] = {false};
    node *temp1 = newHead;
    int i = 0;
    while (temp != NULL && temp1 != NULL)
    {
        if (temp->data == temp1->data)
        {
            ans[i] = true;
        }
        i++;
        temp = temp->next;
        temp1 = temp1->next;
    }
    for (int i = 0; i < count; i++)
    {
        if (ans[i] == false)
        {
            return false;
        }
    }
    return true;
}
int midpoint(node *head)
{
    node *slow = head;
    node *fast = head;
    while (fast != NULL && fast->next != NULL)
    {
        if (fast->next->next == NULL)
        {
            return slow->data;
        }
        fast = fast->next->next;
        slow = slow->next;
    }
    return slow->data;
}
node *midpointAddress(node *head)
{
    node *slow = head;
    node *fast = head;
    while (fast != NULL && fast->next != NULL)
    {
        if (fast->next->next == NULL)
        {
            return slow;
        }
        fast = fast->next->next;
        slow = slow->next;
    }
    return slow;
}
void mergeSortedLinkedList(node *head1, node *head2)
{
    node *newHead = NULL;
    node *newTail = NULL;

    if (head1->data < head2->data)
    {
        newHead = head1;
        newTail = head1;
        head1 = head1->next;
    }
    else
    {
        newHead = head2;
        newTail = head2;
        head2 = head2->next;
    }
    while (head1 != NULL && head2 != NULL)
    {
        if (head1->data < head2->data)
        {
            newTail->next = head1;
            newTail = head1;
            head1 = head1->next;
        }
        else
        {
            newTail->next = head2;
            newTail = head2;
            head2 = head2->next;
        }
    }
    while (head1 != NULL)
    {
        newTail->next = head1;
        newTail = head1;
        head1 = head1->next;
    }
    while (head2 != NULL)
    {
        newTail->next = head2;
        newTail = head2;
        head2 = head2->next;
    }
}

int findNode(node *head, int value)
{
    if (head == NULL)
    {
        return -1;
    }

    if (head->data != value)
    {
        int k = findNode(head->next, value);
        if (k == -1)
        {
            return -1;
        }
        else
        {
            return k + 1;
        }
    }
    else
    {
        return 0;
    }
}

node* evenAfterOdd(node* head)
{
    node* temp = head;
    node* head1 = new node(-1);
    node* head2 = new node(-1);
    node* temp1 = head1;
    node* temp2 = head2;
    while(temp!=NULL)
    {
        node* newNode = new node(temp->data);
        if(temp->data % 2 != 0)
        {
            temp1->next =newNode;
            temp1 = temp1->next;
        }
        else{
            temp2->next =newNode;
            temp2=temp2->next;
        }
        temp = temp->next;
    }
    temp1->next = temp2;
    return head1->next;
}

int main()
{
    node *head1 = input();
    head1 = evenAfterOdd(head1);
    displayLinkedList(head1);
   
    return 0;
}
