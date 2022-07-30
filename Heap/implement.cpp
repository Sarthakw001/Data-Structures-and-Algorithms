#include <bits/stdc++.h>
using namespace std;

class heap // heap class
{
    int v[100];
    int size;

public:
    heap(int s) // constructor
    {
        v[0] = -1;
        size = 0;
    }

    void insert(int val) // insert into heap
    {
        size++;
        int index = size; // 1 based indexing
        v[index] = val;

        while (index > 1)
        {
            int parent = index / 2;

            if (v[parent] < v[index])
            {
                swap(v[parent], v[index]);
                index = parent;
            }
            else
            {
                return;
            }
        }
    }

    void deletefromHeap()
    {
        // step 1 put last element into first
        v[1] = v[size];

        size--;
        // step 2 propogate first element to its correct position
        int i = 1;
        while (i < size)
        {
            int left = 2 * i;      // left child for 1 based indexing
            int right = 2 * i + 1; // right child for 1 based indexing

            if (left < size && v[i] < v[left])
            {
                swap(v[i], v[left]);
                i = left;
            }
            else if (right < size && v[i] < v[right])
            {
                swap(v[i], v[right]);
                i = right;
            }
            else
            {
                return;
            }
        }
    }
    // print
    void print()
    {
        for (int i = 1; i <= size; i++)
        {
            cout << v[i] << " ";
        }
        cout << endl;
    }
};

// heapify algorithm  totally different from above it is applied on an array to convert it into heap;
void heapify(int arr[], int n, int i)
{
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[largest] < arr[left])
    {
        largest = left;
    }
    if (right < n && arr[largest] < arr[right])
    {
        largest = right;
    }

    if (largest != i)
    {
        swap(arr[largest], arr[i]);
        heapify(arr, n, largest);
    }
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6};
    int n = 6;

    for (int i = n / 2 - 1; i >= 0; i--) // calling heapify for non-leaf nodes[0,n/2-1];
    {
        heapify(arr, n, i);
    }
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}