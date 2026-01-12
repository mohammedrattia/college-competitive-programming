#include <bits/stdc++.h>

using namespace std;

#define ll long long

ll ceil2(ll x, ll y = 3)
{
    ll q = x / y;
    if (x >= 0 && x % y != 0)
        q++;
    return q;
}

ll floor2(ll x, ll y = 4)
{
    ll q = x / y;
    if (x < 0 && x % y != 0)
        q--;
    return q;
}

int main()
{
    ll a, b;
    cin >> a >> b;
    a *= 5;
    b *= 7;
    a = ceil2(a);
    b = floor2(b);
    ll ans = b - a + 1;
    cout << (ans < 0 ? 0 : ans) << endl;
}