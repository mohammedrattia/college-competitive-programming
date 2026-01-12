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

using namespace std;

#define ll long long
#define vi vector<int>
#define vll vector<long long>
#define pii pair<int, int>
#define F first
#define S second

#define rep(i, a, b) for (int i = (a); i < (b); i++)
#define rrep(i, a, b) for (int i = (a); i >= (b); i--)

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

const ll MOD = 1e9 + 7;
const int SZ = 1e6;

bool is_valid(int i, int j, int n, int m) { return i < n && i >= 0 && j < m && j >= 0; }

ll n;
vector<pair<ll, ll>> arr;

ll power(ll x, ll n, ll m)
{
    if (n == 0)
        return 1 % m;
    ll u = power(x, n / 2, m);
    u = (u * u) % m;
    if (n % 2 == 1)
        u = (u * x) % m;
    return u % m;
}

ll sum(ll i = 0)
{
    if (i == n)
        return 1;
    ll ret = sum(i + 1) % MOD;
    ret *= power(arr[i].F, arr[i].S + 1, MOD) - 1;
    ret %= MOD;
    ret *= power(arr[i].F - 1, MOD - 2, MOD);
    ret %= MOD;
    return ret;
}

ll cnt = 1;

ll product(ll i = 0)
{
    if (i == n)
        return 1;

    ll ret = power(product(i + 1), arr[i].S + 1, MOD);

    ll p = arr[i].S * (arr[i].S + 1) / 2;

    ret *= power(power(arr[i].F, p, MOD), cnt, MOD);
    ret %= MOD;

    cnt = (cnt * (arr[i].S + 1)) % (MOD - 1);

    return ret;
}

void solve()
{
    cin >> n;
    ll cnt = 1, s = 1, p = 1;
    ll a, b;
    rep(i, 0, n)
    {
        cin >> a >> b;
        arr.push_back({a, b});
        cnt = (cnt * (b + 1)) % MOD;
    }
    s = sum();
    p = product();
    cout << cnt << ' ' << s << ' ' << p;
}

int main()
{
    FAST;
    // int t;
    // cin >> t;
    // while (t--)
    solve();
}