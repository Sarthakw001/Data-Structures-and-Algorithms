#include <iostream>
using namespace std;

int main()
{
    int n;
    cout<<"Enter the Number"<<endl;
    cin >> n;

    int i;
    for (i = 2; i < n; i++)
    {
        if (n % i == 0)
        {
            break;
        }
    }
    if (i == n)
    {
        cout <<  "Prime" << endl;
    }
    else
    {
        cout << "Not Prime" << endl;
    }
    return 0;
}