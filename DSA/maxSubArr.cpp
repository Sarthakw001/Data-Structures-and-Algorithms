#include<iostream>
#include<math.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }

    int max_ending_here = 1;
    int min_ending_here = 1;
    int max_so_far =0;

    for(int i=0;i<n;i++)
    {
        if(a[i]>0)
        {
            max_ending_here =max_ending_here*a[i];
            min_ending_here = min(1,min_ending_here*a[i]);
        }
        else if(a[i]==0)
        {
            max_ending_here = 1;
            min_ending_here =0;
        }
        else
        {
            int temp =max_ending_here;
            max_ending_here = max(min_ending_here*a[i],1);
            min_ending_here = temp*a[i];
        }
        max_so_far = max(max_so_far,max_ending_here);
    }
    cout<<max_so_far<<endl;
}