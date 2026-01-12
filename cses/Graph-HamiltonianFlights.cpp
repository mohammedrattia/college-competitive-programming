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
    cin >> n >> m;
    adj = vector<vll>(n);
    ll a, b;
    rep(i, 0, m)
    {
        cin >> a >> b;
        adj[b - 1].push_back(a - 1);
    }
    ll dp[1 << n][n] = {0};
    dp[1][0] = 1;
    rep(s, 2, 1 << n)
    {
        if (((s & 1) == 0) || (s & (1 << (n - 1)) && s != (1 << n) - 1))
            continue;
        rep(i, 0, n)
        {
            if (s & (1 << i))
            {
                int last = s ^ (1 << i);
                for (auto &e : adj[i])
                {
                    if (s & (1 << e))
                    {
                        dp[s][i] += dp[last][e];
                        dp[s][i] %= MOD;
                    }
                }
            }
        }
    }
    cout << dp[(1 << n) - 1][n - 1] << endl;
}

int main()
{
    FAST;
    // int t;
    // cin >> t;
    // while (t--)
    solve();
}