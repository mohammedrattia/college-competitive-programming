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

const ll INF = 1e18;
const ll MOD = 1e9 + 7;
const ll iMOD = 998244353;
const int SZ = 1e6;

bool is_valid(int i, int j, int n, int m) { return i < n && i >= 0 && j < m && j >= 0; }

mt19937 rnd(time(nullptr));
template <typename T>
T rng(T l, T r)
{
    return uniform_int_distribution<T>(l, r)(rnd);
}

void solve()
{
    ll n, k;
    cin >> n >> k;
    if (k == n - 1)
    {
        if (n == 4)
        {
            cout << -1 << endl;
            return;
        }
        cout << k / 2 << ' ' << n - 1 << endl;
        cout << k / 2 + 1 << ' ' << n - 2 << endl;
        cout << 0 << ' ' << 1 << endl;
        rep(i, 1, n / 2)
        {
            ll a = i;
            ll b = n - i - 1;
            if (a == 0 || a == 1 || a == n / 2 - 1)
            {
                continue;
            }
            cout << a << ' ' << b << endl;
        }
        return;
    }
    cout << k << ' ' << n - 1 << endl;
    rep(i, 1, n / 2)
    {
        ll a = i;
        ll b = n - i - 1;
        if (a == k)
        {
            a = 0;
        }
        if (b == k)
        {
            b = 0;
        }
        cout << a << ' ' << b << endl;
    }
}

int main()
{
    FAST;
    int t;
    cin >> t;
    while (t--)
        solve();
}
