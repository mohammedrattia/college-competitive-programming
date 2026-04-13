#include <iostream>
#include <algorithm>

using namespace std;
typedef long long         ll;

ll lcm(ll a, ll b){ return a*b / __gcd(a, b);}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ll t, st;
    cin >> t >> st;
    while (t--)
    {
        ll n, a, b, c;
        cin >> n >> a >> b >> c;
        if (true)
        {
            ll lac = lcm(a, c);
            ll lbc = lcm(b, c);
            ll lab = lcm(a, b);
            ll lalcb = lcm(a, lbc);
            ll ans = n/(a) - n/(lac) + n/(b) - n/(lbc) - n/(lab) + n/(lalcb);
            cout << ans << "\n";
        }

    }
}
