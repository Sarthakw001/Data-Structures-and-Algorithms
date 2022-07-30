#include <iostream>
#include <math.h>
using namespace std;

int countBalanceBST(int *a, int h)
{
    if (h <= 1)
    {
        return 1;
    }
    if (a[h] != -1)
    {
        return a[h];
    }
    int mod = pow(10, 9) + 7;
    int x = countBalanceBST(a, h - 1);
    int y = countBalanceBST(a, h - 2);

    int ans = ((((long)(x)*x) % mod) + (2 * (long)(x)*y) % mod);
    a[h] = ans;
    return ans;
}

int countBalanceBST_helper(int h)
{
    int *a = new int[h + 1];
    for (int i = 0; i <= h; i++)
    {
        a[i] = -1;
    }
    int ans = countBalanceBST(a, h);
    return ans;
}

int main()
{
    int h = 20;
    cout << countBalanceBST_helper(h) << endl;
}