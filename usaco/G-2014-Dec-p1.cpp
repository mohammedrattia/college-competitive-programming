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
#define vll vector<ll>
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

const ll INF = 1e9;
const ll MOD = 1e9 + 7;
const ll iMOD = 998244353;
const int SZ = 1e6;

bool is_valid(int i, int j, int n, int m) { return i < n && i >= 0 && j < m && j >= 0; }

void solve()
{
    ll n, k;
    cin >> n >> k;
    ll h[n], w[n], s[n];
    rep(i, 0, n) cin >> h[i] >> w[i] >> s[i];
    vector<pll> dp(1 << n, {0, -1});
    dp[0] = {0, INF};
    rep(m, 1, 1 << n)
    {
        rep(j, 0, n)
        {
            if (m & (1 << j))
            {
                dp[m].F += h[j];
                int rem = m ^ (1 << j);
                dp[m].S = max(dp[m].S, min(dp[rem].S - w[j], s[j]));
            }
        }
    }
    ll safety = -1;
    rep(i, 1, (1 << n))
    {
        if (dp[i].F >= k)
            safety = max(safety, dp[i].S);
    }
    if (safety < 0)
        cout << "Mark is too tall" << endl;
    else
        cout << safety << endl;
}

int main()
{
    FAST;
    freopen("guard.in", "r", stdin);
    freopen("guard.out", "w", stdout);
    // int t;
    // cin >> t;
    // while (t--)
    solve();
}
