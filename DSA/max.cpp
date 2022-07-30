#include <iostream>
using namespace std;

int main()
{
    int a, b;
    cout << "Enter two Numbers" << endl;

    cin >> a >> b;

    int max;

    if (a > b)
    {
        max = a;
    }
    else
    {
        max = b;
    }

    cout << "The max is : " << max << endl;
}