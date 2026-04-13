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

void moveEgcdStep(ll &a, ll &b, ll q)
{
    ll next = a - q * b;
    a = b;
    b = next;
}
ll egcd(ll a, ll b, ll &x0, ll &y0)
{
    ll r0 = a, r1 = b;
    ll x1 = y0 = 0, y1 = x0 = 1;
    while (r1 != 0)
    {
        ll q = r0 / r1;
        moveEgcdStep(x0, x1, q);
        moveEgcdStep(y0, y1, q);
        moveEgcdStep(r0, r1, q);
    }
    return r0;
}

// SOLVE SPACE
void solve()
{
    // freopen("file.in", "r", stdin);
    // freopen("file.out", "w", stdout);
    ll n, m, a, b;
    cin >> n >> m >> a >> b;
    a %= n, b %= m;
    ll g = gcd(n, m);
    if (g % 2 == 0)
        g /= 2;

    if (gcd(n, a) == 1 && gcd(m, b) == 1 && g == 1)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
    // cout << gcd(n, a) << ' ' << lcm(n, a) << ' ' << n * a << endl;
    // cout << gcd(m, b) << ' ' << lcm(m, b) << ' ' << m * b << endl;
}

int main()
{
    // FAST;
    int t;
    cin >> t;
    while (t--)
        solve();
}
