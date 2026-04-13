#include <iostream>

using namespace std;

#define ll long long
#define rep(i, n) for (int i = 0; i < n; i++)

int main()
{
    ll t;
    cin >> t;
    while (t--)
    {
        ll a, b;
        cin >> a >> b;

        if (a == 0)
            cout << 1 << endl;
        else
            cout << a + b * 2 + 1 << endl;
    }
}
