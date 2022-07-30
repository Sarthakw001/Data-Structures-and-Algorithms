#include <iostream>
using namespace std;

int stairCase(int a[],long long int n)
{
    if (n < 0)
    {
        return 0;
    }
    if (n == 0)
    {
        return 1;
    }
    if(a[n]!=-1)
    {
        return a[n];
    }
    long long int x = stairCase(a,n - 1);
    long long int y = stairCase(a,n - 2);

    long long int z = stairCase(a,n - 3);

    long long int output = x+y+z;

    a[n] = output;

    return  output;
}
long long int stairCase_helper(long long int n)
{
     int ans[n+1];
    for(long long int i=0;i<=n;i++)
    {
        ans[i]=-1;
    }
    return stairCase(ans,n);
}

 int main()
{
     long long int n = 50;
    cout << stairCase_helper(n) << endl;

    return 0;
}