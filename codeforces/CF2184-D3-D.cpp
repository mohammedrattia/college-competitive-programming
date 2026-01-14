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

const ll INF = 1e18;
const ll MOD = 1e9 + 7;
const ll iMOD = 998244353;
const int SZ = 1e5 + 1;

bool is_valid(int i, int j, int n, int m) { return i < n && i >= 0 && j < m && j >= 0; }
int dx[4] = {0, 1, 0, -1};
int dy[4] = {-1, 0, 1, 0};

mt19937 rnd(time(nullptr));
template <typename T>
T rng(T l, T r)
{
    return uniform_int_distribution<T>(l, r)(rnd);
}

ll nCr(ll n, ll r)
{
    // Invalid case
    if (r > n)
        return 0;
    // Base cases
    if (r == 0 || n == r)
        return 1;

    double res = 0;
    for (ll i = 0; i < r; i++)
    {
        res += log(n - i) - log(i + 1);
    }

    return (ll)round(exp(res));
}

void solve()
{
    // freopen("file.in", "r", stdin);
    // freopen("file.out", "w", stdout);
    ll n, k;
    cin >> n >> k;
    ll j = 1, sum = 0;
    for (ll i = 1; i <= n; i <<= 1, j++)
    {
        if (j > k)
        {
            break;
        }
        for (ll y = 0; j + y <= k && y <= j; y++)
        {
            sum += nCr(j - 1, y);
            if (i == n)
            {
                break;
            }
        }
    }
    cout << max(0ll, n - sum) << endl;
}

int main()
{
    // FAST;
    int t;
    cin >> t;
    while (t--)
        solve();
}
