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
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
#define PB push_back

#define pii pair<int, int>
#define MP make_pair
#define F first
#define S second

#define rep(i, a, b) for (int i = (a); i < (b); i++)
#define rrep(i, a, b) for (int i = (a); i >= (b); i--)

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

ll n, m;
vector<vll> adj;

void solve()
{
    cin >> n;
    adj = vector<vll>(n, vll(n));
    ll a;
    rep(i, 0, n)
    {
        rep(j, 0, n)
        {
            cin >> adj[i][j];
        }
    }
    ll dp[(1 << n) + 1];
    rep(m, 0, 1 << n)
    {
        ll cost = 0;
        rep(i, 0, n) rep(j, 0, n)
        {
            if ((m >> i) & 1 && (m >> j) & 1)
                cost += adj[i][j];
        }
        cost >>= 1;
        dp[m] = cost;
        for (int j = m; j; j = (j - 1) & m)
        {
            int s = j ^ m;
            dp[m] = max(dp[m], dp[j] + dp[s]);
        }
    }
    cout << dp[(1 << n) - 1] << endl;
}

int main()
{
    FAST;
    // int t;
    // cin >> t;
    // while (t--)
    solve();
}