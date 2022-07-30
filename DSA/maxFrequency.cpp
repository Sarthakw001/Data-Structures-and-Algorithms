#include <iostream>
#include <unordered_map>
#include <vector>
#include <limits.h>
using namespace std;

int maxFreq(int a[], int size)
{
    unordered_map<int, int> freq;
    for (int i = 0; i < size; i++)
    {
        freq[a[i]] = freq[a[i]] + 1;
    }
    int max = INT_MIN;
    int res;
    for (auto x : freq)
    {
        if (x.second > max)
        {
            max = x.second;
            res = x.first;
        }
    }
    return res;
}

int main()
{
    int a[10] = {2, 2, 2, 2, 2, 5, 5, 5, 5, 5};
    int max = maxFreq(a, 10);
    cout << max << endl;
    return 0;
}