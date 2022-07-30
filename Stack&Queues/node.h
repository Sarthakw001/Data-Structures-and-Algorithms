#include <bits/stdc++.h>
using namespace std;
template <typename T>

class node
{
    public:
    T val;
    T* next;
    T* prev;

    node(T v)
    {
        val = v;
        next=NULL;
        prev=NULL;
    }
};