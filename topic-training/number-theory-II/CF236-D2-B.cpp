// #pragma GCC optimize("O2")

#include <iostream>
#include <string.h>
#include <string>
#include <numeric>
#include <array>
#include <vector>
#include <algorithm>
#include <cmath>
#include <math.h>
#include <climits>
#include <map>
#include <set>
#include <unordered_set>
#include <queue>
#include <stack>
#include <unordered_map>
#include <random>

using namespace std;

// BASIC DEFINES
#define ll long long
#define vi vector<int>
#define vll vector<long long>
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second

// LOOP DEFINES
#define rep(i, a, b) for (ll i = (a); i < (b); i++)
#define rrep(i, a, b) for (ll i = (a); i >= (b); i--)

// OTHER DEFINES
#define all(x) (x).begin(), (x).end()
#define PB push_back
#define MP make_pair
#define sz(x) (int)(x).size()
#define SQ(a) (a) * (a)
#define dbg(x) cout << #x << " = " << x << '\n'
#define FAST                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
#define endl '\n'

// CONSTANTS
const ll INF = 1e18;
const ll MOD = 2 << 30;
const ll iMOD = 998244353;
const int SZ = 1e6 + 1;

// SOLVE SPACE

vll spf;
void sieve(ll n)
{
    spf = vll(n + 1, 1);
    spf[0] = 0;
    for (int i = 2; i <= n; i++)
    {
        if (spf[i] == 1)
        {
            for (int j = i; j <= n; j += i)
            {
                if (spf[j] == 1)
                    spf[j] = i;
            }
        }
    }
}

void solve()
{
    // freopen("file.in", "r", stdin);
    // freopen("file.out", "w", stdout);
    ll a, b, c;
    cin >> a >> b >> c;

    vll ndiv(SZ, 0);
    for (ll i = 1; i < SZ; i++)
    {
        ll x = i, val = 1;
        while (x != 1)
        {
            ll a = spf[x], cnt = 1;
            x = x / a;
            cnt++;
            while (x % a == 0)
            {
                x = x / a;
                cnt++;
            }
            val *= cnt;
        }
        ndiv[i] = val;
    }
    ll ans = 0;
    rep(i, 1, a + 1)
    {
        rep(j, 1, b + 1)
        {
            rep(k, 1, c + 1)
            {
                ans += ndiv[i * j * k];
                ans %= MOD;
            }
        }
    }
    cout << ans << endl;
}

int main()
{
    FAST;
    sieve(SZ);
    // int t;
    // cin >> t;
    // while (t--)
    solve();
}
