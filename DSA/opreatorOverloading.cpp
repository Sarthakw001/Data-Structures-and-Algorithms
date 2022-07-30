#include <iostream>
using namespace std;

class fraction
{
private:
    int numerator;
    int denominator;

public:
   
    fraction(int numerator, int denominator)
    {
        this->numerator = numerator;
        this->denominator = denominator;
    }

    void simplify()
    {
        int gcd = 1;
        int j = min(numerator, denominator);
        for (int i = 1; i <= j; i++)
        {
            if (numerator % i == 0 && denominator % i == 0)
            {
                gcd = i;
            }
        }
        numerator = numerator / gcd;
        denominator = denominator / gcd;
    }
    fraction operator+(const fraction &f2)
    {
        int lcm = denominator * f2.denominator;
        int x = lcm / denominator;
        int y = lcm / f2.denominator;
        int num = x * numerator + y * f2.numerator;

        fraction fNew(num,lcm);
        fNew.simplify();
        return fNew;
    }
    fraction operator*(const fraction&f2){
        int n = numerator * f2.numerator;
        int d= denominator * f2.denominator;

        fraction fNew(n,d);
        fNew.simplify();
        return fNew;
    }
    fraction& operator++()
    {
        numerator = numerator+denominator;
        denominator = denominator;
        simplify();
        return *this;
    }
    fraction operator++(int)
    {
        fraction fNew(numerator,denominator);
        numerator=numerator+denominator;
        denominator=denominator;
        simplify();
        fNew.simplify();
        return fNew;
    }
    fraction& operator+=(const fraction &f2)
    {
        int lcm = denominator * f2.denominator;
        int x = lcm / denominator;
        int y = lcm / f2.denominator;
        int num = x * numerator + y * f2.numerator;

       numerator=num;
       denominator=lcm;
       simplify();
        return *this;
    }
    void display() const
    {
        cout << numerator << "/" << denominator << endl;
    }
};