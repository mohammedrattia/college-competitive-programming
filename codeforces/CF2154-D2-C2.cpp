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

#define ll long long
#define vi vector<int>
#define vll vector<long long>
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second

#define rep(i, a, b) for (ll i = (a); i < (b); i++)
#define rrep(i, a, b) for (ll i = (a); i >= (b); i--)

#define all(x) (x).begin(), (x).end()
#define PB push_back
#define MP make_pair
#define sz(x) (int)(x).size()
#define SQ(a) (a) * (a)

#define FAST                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
#define dbg(x) cout << #x << " = " << x << '\n'
#define endl '\n'

const ll INF = 1e9 + 5;
const ll MOD = 1e9 + 7;
const ll iMOD = 998244353;
const ll SZ = 2 * 1e5 + 5;

bool is_valid(int i, int j, int n, int m) { return i < n && i >= 0 && j < m && j >= 0; }

mt19937 rnd(time(nullptr));
template <typename T>
T rng(T l, T r)
{
    return uniform_int_distribution<T>(l, r)(rnd);
}

vll spf(SZ, 1);

void solve()
{
    ll n;
    cin >> n;
    pll arr[n];
    vector<set<ll>> s(n);

    rep(i, 0, n)
    {
        cin >> arr[i].S;
    }
    ll m1 = INF, m2 = INF;
    rep(i, 0, n)
    {
        cin >> arr[i].F;
        if (arr[i].F < m1)
        {
            m2 = m1;
            m1 = arr[i].F;
        }
        else if (arr[i].F < m2)
        {
            m2 = arr[i].F;
        }
    }
    sort(arr, arr + n);

    rep(i, 0, n)
    {
        ll x = arr[i].S;
        while (x != 1)
        {
            s[i].insert(spf[x]);
            x = x / spf[x];
        }
    }

    map<ll, ll> freq;
    vector<pll> primes;
    primes.reserve(SZ);
    rep(i, 0, n)
    {
        for (auto &e : s[i])
        {
            ll x = ++freq[e];
            if (x >= 2)
            {
                cout << 0 << endl;
                return;
            }
            primes.push_back({e, i});
        }
    }
    sort(primes.begin(), primes.end());

    ll ans = m1 + m2;
    rep(i, 0, n)
    {
        ll x = arr[i].S + 1;
        while (x != 1)
        {
            if (freq[spf[x]])
            {
                ans = min(ans, arr[i].F);
            }
            x = x / spf[x];
        }
    }
    if (ans == m1)
    {
        cout << ans << endl;
        return;
    }

    pll least = arr[0];

    for (pll &e : primes)
    {
        ll steps = e.F - (arr[0].S % e.F);
        if (e.S != 0)
            ans = min(ans, steps * arr[0].F);
    }

    cout << ans << endl;
}

int main()
{
    FAST;
    spf[0] = 0;
    for (ll i = 2; i < SZ; i++)
    {
        if (spf[i] == 1ll)
        {
            for (ll j = i; j < SZ; j += i)
            {
                if (spf[j] == 1ll)
                    spf[j] = i;
            }
        }
    }
    int t;
    cin >> t;
    while (t--)
        solve();
}
