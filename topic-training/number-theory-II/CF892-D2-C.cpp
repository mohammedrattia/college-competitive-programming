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
const int SZ = 1e5 + 1;

// SOLVE SPACE

ll gcd(ll a, ll b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

// SOLVE SPACE
vll arr;
ll calc_gcd(ll l, ll r)
{
    ll g = arr[l];
    rep(i, l, r) g = gcd(g, arr[i]);
    return g;
}

void solve()
{
    // freopen("file.in", "r", stdin);
    // freopen("file.out", "w", stdout);
    ll n;
    cin >> n;
    arr = vll(n);
    ll cnt = 0;
    rep(i, 0, n)
    {
        cin >> arr[i];
        cnt += arr[i] == 1;
    }
    if (cnt)
    {
        cout << n - cnt << endl;
        return;
    }

    ll l = 0, r = 0, ans = 1e18, g = arr[0];
    while (l != n)
    {
        g = calc_gcd(l, r);
        if (g == 1)
            ans = min(ans, r - l);
        if (g > 1 && r != n)
            r++;
        else
            l++;
    }
    if (ans < 2 || ans == (ll)(1e18))
    {
        cout << -1 << endl;
        return;
    }
    cout << ans - 2 + n << endl;
}

int main()
{
    // FAST;
    // int t;
    // cin >> t;
    // while (t--)
    solve();
}
