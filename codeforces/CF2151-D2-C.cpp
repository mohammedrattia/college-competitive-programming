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
    vll arr(2 * n), pre[2] = {vll(2 * n, 0), vll(2 * n, 0)};
    rep(i, 0, 2 * n) cin >> arr[i];
    rep(i, 1, 2 * n)
    {
        pre[i % 2][i] += pre[i % 2][i - 1];
        pre[(i - 1) % 2][i] += pre[(i - 1) % 2][i - 1];
        if (i % 2)
            pre[i % 2][i] += arr[i] - arr[i - 1];
        else
            pre[i % 2][i] += arr[i] - arr[i - 1];
    }
    ll ans = 0;
    rep(i, 0, n)
    {
        cout << pre[(i + 1) % 2][2 * n - i - 1] - pre[(i + 1) % 2][i] + ans << ' ';
        ans += arr[2 * n - i - 1] - arr[i];
    }
    cout << endl;
}

int main()
{
    // FAST;
    int t;
    cin >> t;
    while (t--)
        solve();
}
