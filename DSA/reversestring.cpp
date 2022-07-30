#include <iostream>
using namespace std;
#include <string.h>

void reverse(string s)
{
    if (s == "")
    {
        return;
    }
    reverse(s.substr(1));
    cout << s[0];
}

int main()
{
    string s;
    cin >> s;
    reverse(s);
    return 0;
}