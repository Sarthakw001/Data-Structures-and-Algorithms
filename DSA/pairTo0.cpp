#include <iostream>
#include <unordered_map>
#include <vector>
#include <limits.h>
using namespace std;

void pairSum(int a[], int size)
{
    unordered_map<int, int> hash;
    int count = 0;
    for(int i=0;i<size;i++)
    {
        hash[a[i]]++;
    }
    

}

int main()
{
    int a[5]={2,3,-2,2,5};
    pairSum(a,5);
    return 0;
}