#include<vector>
using namespace std;

template <class T>

class treeNode
{
    public:
    T data;
    vector <treeNode*> children ;

    treeNode(T data)
    {
        this->data = data;
    }
};