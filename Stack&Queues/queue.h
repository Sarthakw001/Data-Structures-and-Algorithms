#include <bits/stdc++.h>
using namespace std;
template <typename T>

class queue
{
    private:
        vector<T> q;
        int n;
    public:
    void push(T v)
    {
        q.push_front(v);
    }
};