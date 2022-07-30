#include<bits/stdc++.h>
#include "node.h"
using namespace std;
template <typename T>

class stackL
{
    public:
    node<T>* head =NULL;
    node<T>* mid = NULL;
    int size = 0;

    void push(T x)
    {
        node<T>* temp = new node(x);
        if(size == 0)
        {
            head = temp;
            mid = temp;
            size++;
            return;
        }
        head->next = temp;
        temp->prev = head;

        head = head->next;
        if(size%2 == 1)
        {
            mid = mid->next;
        }
        size++;
    }
    void pop()
    {
        if(size!=0)
        {
            if(size==1)
            {
                head =NULL;
                mid=NULL;
            }
            else
            {
                head = head->prev;
                head->next = NULL;
                if(size%2 == 0)
                {
                    mid = mid->prev;
                }
            }
            size--;
        }
    }
    T findMiddle()
    {
        if(size == 0)
        {
            return -1;
        }
        return mid->val;
    }
    void deleteMiddle()
    {
        if(size!=0)
        {
            if(size==1)
            {
                head =NULL;
                mid = NULL;
            }
            else if(size == 2)
            {
                head = head->prev;
                mid = mid->prev;
                head->next = NULL;
            }
            else
            {
                mid->next->prev = mid->prev;
                mid->prev->nect = mid->next;
                if(size%2 == 0)
                {
                    mid = mid->prev;
                }
                else
                {
                    mid = mid->next;
                }
            }
            size--;
        }
    }
};