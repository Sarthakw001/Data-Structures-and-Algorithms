#include <iostream>
#include <unordered_map>
#include <vector>
#include <limits.h>
using namespace std;

vector<int> intersectionArr(int a[], int b[], int n, int m)
{
    vector<int> v;
    unordered_map<int, int> hash;
    if (n >= m)
    {
        for (int i = 0; i < m; i++)
        {
            hash[a[i]]=1;
        }
        for (int i = 0; i < n; i++)
        {
            if (hash.count(b[i]) > 0)
            {
                v.push_back(b[i]);
            }
        }
    }
    if (m > n)
    {
        for (int i = 0; i < n; i++)
        {
            hash[b[i]]++;
        }
        for (int i = 0; i < m; i++)
        {
            if (hash.count(a[i]) > 0)
            {
                v.push_back(a[i]);
            }
        }
    }
    return v;
}

int main()
{
    int a[4] = {2, 3, 4, 7};
    int b[6] = {2, 6, 8, 5, 4, 3};
    vector<int> v = intersectionArr(a, b, 4, 6);
   
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << endl;
    }
    return 0;
}
