#include <iostream>
using namespace std;

class array
{
private:
    int *data;
    int nextIndex;
    int capacity;

public:
    array()
    {
        data = new int[5];
        nextIndex = 0;
        capacity = 5;
    }
    array(const array&a)
    {
       this->data=new int [a.capacity];
        for(int i=0;i<a.nextIndex;i++)
        {
            this->data[i]=a.data[i];
        }
        this->nextIndex=a.nextIndex;
        this->capacity=a.capacity;
    }
    void operator=(const array&a)
    {
         this->data=new int [a.capacity];
        for(int i=0;i<a.nextIndex;i++)
        {
            this->data[i]=a.data[i];
        }
        this->nextIndex=a.nextIndex;
        this->capacity=a.capacity;
    }
    void addElement(int element)
    {
        if (nextIndex == capacity)
        {
            int *newData = new int[2 * capacity];
            for (int i = 0; i < capacity; i++)
            {
                newData[i] = data[i];
            }
            delete[] data;
            data = newData;
            capacity *= 2;
        }
        data[nextIndex] = element;
        nextIndex++;
    }
    int getData(int i)
    {
        if (i < nextIndex)
            return data[i];
        else
            return -1;
    }
    void updateElement(int i, int element)
    {
        if (i < nextIndex)
            data[i] = element;
        else if (i == nextIndex)
        {
            addElement(element);
        }
        else
        {
            return;
        }
    }
    void displayElement() const
    {
        for (int i = 0; i < nextIndex; i++)
        {
            cout << data[i] << " ";
        }
        cout << endl;
    }
};