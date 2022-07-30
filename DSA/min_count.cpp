#include<iostream>
#include<limits.h>
#include<math.h>
using namespace std;


int minCount(int n)
{
    if(n<=3)
    {
        return n;
    }
    int ans = INT_MAX;
    for(int i=1;i<=(int)sqrt(n);i++)
    {
        int x = minCount (n - pow(i,2));
        ans = min(ans,x);
    }
    return 1+ans;

}


int main()
{
    int n = 9;
    cout<<minCount(n)<<endl;
}