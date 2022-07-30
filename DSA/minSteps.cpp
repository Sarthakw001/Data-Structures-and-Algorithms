#include <iostream>
#include <limits.h>
using namespace std;

// int minSteps(int n)  // recursiveApproach
// {
//     if(n<=1)
//     {
//         return 0;
//     }
//     int x = minSteps(n-1);

//     int y = INT_MAX,z = INT_MAX;
//     if(n%2==0)
//     {
//         y = minSteps(n/2);
//     }
//     if(n%3 == 0)
//     {
//         z = minSteps(n/3);
//     }

//     return 1 + min(x,min(y,z));

// }

// int minSteps_helper(int a[],int n)   //Memoization
// {
//     if(n<=1)
//     {
//         return 0;
//     }
//     if(a[n] != -1)
//     {
//         return a[n];
//     }

//     int x = minSteps_helper(a,n-1);
//     int y = INT_MAX;
//     int z = INT_MAX;

//     if(n%2 == 0)
//     {
//         y = minSteps_helper(a,n/2);
//     }
//     if(n%3 == 0)
//     {
//         z= minSteps_helper(a,n/3);
//     }
//     int output = 1 + min(x,min(y,z));
//     a[n] =  output;

//     return output;

// }

// int minSteps(int n)
// {
//     int a[n+1];
//     for(int i=0;i<=n;i++)
//     {
//         a[i] = -1;
//     }
//     int x = minSteps_helper(a,n);
//     return x;
// }

int main()
{
    int n = 8;

    int ans[n + 1];

    ans[0] = 0;
    ans[1] = 0;
    for (int i = 2; i <= n; i++)
    {
        // if(!(i%2) && (i%3))
        // {
        //     ans[i] = 1 + min(ans[i-1],ans[i/2]);
        // }
        // else if((i%2) && !(i%3))
        // {
        //     ans[i] = 1 + min(ans[i-1],ans[i/3]);
        // }
        // else if(!(i%2) && !(i%3))
        // {
        //     ans[i] = 1 + min (ans[i-1],min(ans[i/2],ans[i/3]));
        // }
        // else
        // {
        //     ans[i] = 1+ ans[i-1];
        // }

         int ans1 =   1+ans[i-1];
        if(i%2 == 0)
        {
            ans1 =  min(ans1,ans[i/2]+1);
        }
        if(i%3 == 0)
        {
            ans1 =  min(ans1,ans[i/3]+1);
        }

        ans[i]  = ans1;

    }

    cout << ans[n] << endl;

    return 0;
}