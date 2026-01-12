#include <bits/stdc++.h>

using namespace std;

const long long INF = 1e9;
const long long MOD = 1e9 + 7;
const long long iMOD = 998244353;
const int SZ = 1e6;

#define ll long long

vector<ll> v;

ll rec(ll mask, ll idx = 0)
{
    if (idx == v.size())
        return 0;
    ll ret = 0;
    if (mask & (1 << idx))
    {
        ret += v[idx];
    }
    return ret + rec(mask, idx + 1);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    ll n;
    cin >> n;

    for (ll i = 1; i <= n; i <<= 1)
    {
        if (i & n)
            v.push_back(i & n);
    }

    for (int mask = 0; mask < (1 << v.size()); mask++)
    {
        cout << rec(mask) << endl;
    }
}
