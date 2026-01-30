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
const ll MOD = 1e9 + 7;
const ll iMOD = 998244353;
const int SZ = 1e6 + 1;

ll gcd(ll a, ll b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}
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

// SOLVE SPACE

void solve()
{
    // freopen("file.in", "r", stdin);
    // freopen("file.out", "w", stdout);
    ll n;
    cin >> n;
    vll arr(n);
    rep(i, 0, n) cin >> arr[i];

    vector<vll> factors(n);
    for (ll i = 0; i < arr.size(); i++)
    {
        ll x = arr[i];
        while (x != 1)
        {
            ll a = spf[x];
            factors[i].push_back(spf[x]);
            x = x / a;
            while (x % a == 0)
                x = x / a;
        }
    }

    ll l = 0, r = 0, ans = -1;
    vll freq(SZ, 0);
    while (r != n)
    {
        ll x = arr[r++];
        for (ll a : factors[r - 1])
        {
            while (freq[a] > 0)
            {
                for (ll e : factors[l])
                {
                    freq[e]--;
                }
                l++;
            }
            freq[a]++;
        }
        if (r - l > 1)
            ans = max(ans, r - l);
    }

    cout << ans << endl;
}

int main()
{
    FAST;
    int t;
    cin >> t;
    sieve(SZ);
    while (t--)
        solve();
}
