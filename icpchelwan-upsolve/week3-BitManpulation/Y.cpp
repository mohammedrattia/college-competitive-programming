#include <bits/stdc++.h>

using namespace std;

const long long INF = 1e9;
const long long MOD = 1e9 + 7;
const long long iMOD = 998244353;
const int SZ = 1e6;

#define ll long long

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    ll n;
    cin >> n;
    vector<ll> s;
    for (ll i = 1; i <= n; i <<= 1)
    {
        if (i & n)
            s.push_back(i & n);
    }
    for (ll i = 0; i < (1 << s.size()); i++)
    {
        ll ans = 0;
        for (ll j = 0; j <= s.size(); j++)
        {
            if (i & 1 << j)
                ans += s[j];
        }
        cout << ans << endl;
    }
}
