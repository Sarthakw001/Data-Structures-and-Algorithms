#include <bits/stdc++.h>
using namespace std;

void solve(int arr[], int size)
{
    int i = 0, j = size - 1;
    while (i < j)
    {
        if (arr[i] < 0 && arr[j] > 0)
        {
            i++;
            j--;
        }
        else if (arr[i] > 0 && arr[j] < 0)
        {
            swap(arr[i], arr[j]);
            i++;
            j--;
        }
        else
        {
            i++;
        }
    }
}
void display(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " " << endl;
    }
    cout << endl;
}
int main()
{
    int arr[] = {-12, 11, -13, -5, 6, -7, 5, -3, 11};
    int arr_size = sizeof(arr) / sizeof(arr[0]);

    // Function Call
    solve(arr, 9);
    display(arr, 9);
    
    return 0;
}