#include <iostream>
using namespace std;

int main()
{
    int n;
    cout << "Enter the size of array" << endl;
    cin >> n;

    int a[n];
    cout << "Enter array data" << endl;
    for (int i = 0; i < n; i++)
    {
        int data;
        cin >> data;

        a[i] = data;
    }

    int max = a[0];
    for (int i = 1; i < n; i++)
    {
        if (a[i] > max)
        {
            max = a[i];
        }
    }

    cout << "The max element is : " << max << endl;
}