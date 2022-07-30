#include <bits/stdc++.h>
using namespace std;
template <typename T>

class Stack
{
    public:
    vector<T> stack;
    int n=0;
    void push(T v)
    {
        stack.push_back(v);
        n++;
    }
    void pop(T v)
    {
        if(!stack.empty())
        {
            stack.pop_back();
            n--;
        }
        cout<<"stack is empty"<<endl;
    }
    T top (T v)
    {
        if(!stack.empty())
        {
            return stack[n];
        }
        return INT_MIN;
    }
    int size()
    {
        return n;
    }
};