#include<iostream>
using namespace std;
class base {
    public:
    base() {cout<<"Base";}
};
class derived : public base
{
    public:
    derived(int i){cout<<i;}
};
int main()
{
    derived d2(10);
    return 0;
}