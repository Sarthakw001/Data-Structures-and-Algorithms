#include <iostream>
using namespace std;

void reverse(int a[],int start,int end)
{
   while (start<=end)
   {
       int temp =a[start];
       a[start]=a[end];
       a[end]=temp;
       start+=1;
       end-=1;
   }
}

int main()
{
    int a[] = {1, 2, 3, 4, 5};
    reverse(a,0,4);
    for (int i = 0; i < 5; i++)
    {
        cout << a[i] << " ";
    }
}