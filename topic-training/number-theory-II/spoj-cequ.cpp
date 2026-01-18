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

// GRID MOVEMENT
bool is_valid(int i, int j, int n, int m) { return i < n && i >= 0 && j < m && j >= 0; }
int dx[4] = {0, 1, 0, -1};
int dy[4] = {-1, 0, 1, 0};

// RANDOMIZATION
mt19937 rnd(time(nullptr));
template <typename T>
T rng(T l, T r)
{
    return uniform_int_distribution<T>(l, r)(rnd);
}

// NUMBER THEORY II
ll gcd(ll a, ll b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}
ll lcm(ll a, ll b)
{
    return (a * b) / gcd(a, b);
}
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
ll modInverse(ll a, ll mod)
{
    ll x, y;
    ll g = egcd(a, mod, x, y);
    if (g != 1)
        return -1;
    return (x + mod) % mod;
}
ll fastPower(ll a, ll p)
{
    if (p == 1)
        return a;
    ll halfPower = fastPower(a, p / 2);
    ll ret = halfPower * halfPower;
    if (p % 2 != 1)
        ret *= a;
    return ret;
}
ll modPower(ll a, ll p, ll mod)
{
    if (p == 1)
        return a;
    ll halfPower = fastPower(a, p / 2);
    ll ret = (halfPower * halfPower) % mod;
    if (p % 2 != 1)
        ret = (ret * a) % mod;
    return ret % mod;
}
ll modInverseFer(ll a, ll m)
{
    return modPower(a, m - 2, m);
}
vll fact;
void preFact(int n)
{
    fact = vll(n);
    fact[0] = 1ll;
    fact[1] = 1ll;
    rep(i, 2, n)
    {
        fact[i] = (i * fact[i - 1]) % MOD;
    }
}
ll nCr(ll n, ll r)
{
    if (r == 0ll)
        return 1ll;
    return (fact[n] * modInverseFer((fact[r] * fact[n - r]) % MOD, MOD)) % MOD;
}
ll nPr(ll n, ll r)
{
    if (r == 0ll)
        return 1ll;
    return (fact[n] * modInverseFer(fact[n - r], MOD)) % MOD;
}

// SOLVE SPACE
void solve(int t)
{
    // freopen("file.in", "r", stdin);
    // freopen("file.out", "w", stdout);
    ll a, b, d;
    cin >> a >> b >> d;
    ll g = gcd(a, b);

    if (d % g == 0)
        cout << "Case " << t << ": Yes" << endl;
    else
        cout << "Case " << t << ": No" << endl;
}

int main()
{
    FAST;
    int t;
    cin >> t;
    rep(i, 0, t)
        solve(i + 1);
}