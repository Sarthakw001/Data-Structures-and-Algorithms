#include <iostream>
using namespace std;

int main()
{
    int a, b, c, d;
    cout << "Enter four Numbers" << endl;
    cin >> a >> b >> c >> d;

    int total = a + b + c + d;

    double avg = (double)total / 4;

    cout << "The total is : " << total << endl;
    cout << "The average is : " << avg << endl;

    return 0;
}