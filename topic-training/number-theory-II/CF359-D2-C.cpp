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

// SOLVE SPACE

ll modPower(ll a, ll p, ll mod)
{
    if (p == 0)
        return 1;
    if (p == 1)
        return a;
    ll halfPower = modPower(a, p / 2, mod);
    ll ret = (halfPower * halfPower) % mod;
    if (p % 2 == 1)
        ret = (ret * a) % mod;
    return ret % mod;
}

void solve()
{
    // freopen("file.in", "r", stdin);
    // freopen("file.out", "w", stdout);
    ll n, x;
    cin >> n >> x;
    vll arr(n);
    ll sum = 0;
    rep(i, 0, n)
    {
        cin >> arr[i];
        sum += arr[i];
    }
    priority_queue<ll, vll, greater<>> pq;
    for (ll a : arr)
    {
        pq.push(sum - a);
    }
    ll ans = pq.top();
    while (!pq.empty())
    {
        ll cur = pq.top(), cnt = 0;
        while (!pq.empty() && pq.top() == cur)
        {
            cnt++;
            pq.pop();
        }
        if (cnt % x != 0)
            break;
        else
        {
            rep(i, 0, (cnt / x))
                pq.push(cur + 1);
        }
        ans = pq.top();
    }
    cout << modPower(x, min(sum, ans), MOD) << endl;
}

int main()
{
    FAST;
    // int t;
    // cin >> t;
    // while (t--)
    solve();
}
