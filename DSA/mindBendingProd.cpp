#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    int lp = 1;
    int ans[n];
    for (int i = 0; i < n; i++)
    {
        ans[i] = lp;
        lp = lp * a[i];
    }
    int rp = 1;
    for (int i = n - 1; i >= 0; i--)
    {
        ans[i] = ans[i] * rp;
        rp = rp * a[i];
    }
    for (int i = 0; i < n; i++)
    {
        cout << ans[i] << endl;
    }
    return 0;
}
