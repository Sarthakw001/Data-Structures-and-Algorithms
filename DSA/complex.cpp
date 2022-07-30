#include <iostream>
using namespace std;

class complex
{
private:
    int real;
    int imag;

public:
    complex(int r, int i)
    {
        real = r;
        imag = i;
    }
    void display()
    {
        if (imag < 0)
        {
            cout << real << " - " << (-1) * imag << "i" << endl;
        }
        else
        {

            cout << real << " + " << imag << "i" << endl;
        }
    }
    void add(const complex &c2)
    {
        this->real = this->real + c2.real;
        this->imag = this->imag + c2.imag;
    }
    void multiply(const complex &c2)
    {
        int r = real * c2.real;
        int i = (imag * c2.imag) * (-1);
        int ri = real * c2.imag;
        int ir = c2.real * imag;

        real = r + i;
        imag = ri + ir;
    }
};