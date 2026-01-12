#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define rep(a, b, c) for (int a = b; a < c; a++)
#define rrep(a, b, c) for (int a = b; a >= c; a--)
#define F first
#define S second
#define pr pair<long long, long long>
#define endl '\n'

const ll N = 1000001;
const ll mod = 1e9+7;

ll ans[N];
ll mid[N];
ll all[N];

void solve()
{
    ll n;
    cin >> n;
    cout << ans[n] << endl;
}

void precalc()
{
    ans[0] = 0; mid[0] = 0; all[0] = 0;
    ans[1] = 1; mid[1] = 0; all[1] = 1;
    rep(i, 2, N)
    {
        mid[i-1] = ((ans[i-1] + mod - all[i-2]) % mod + mod - ans[i-2]) % mod;
        all[i] = all[i-1]*i;
        ans[i] = (((all[i-1] + mid[i-1]*(i-2)/2) % mod + all[i-2]*(i-2)) % mod + ans[i-1]) % mod;
        all[i] %= mod;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    precalc();
    int t;
    cin >> t;
    while (t--)
        solve();
}

