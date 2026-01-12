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
#define pii pair<int, int>
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
    ll n, m;
    cin >> n >> m;
    vector<vll> dp(n, vll(m + 1, 0));
    ll arr[n];
    rep(i, 0, n) cin >> arr[i];
    if (arr[0] == 0)
    {
        rep(i, 0, m + 1) dp[0][i] = 1;
    }
    else
        dp[0][arr[0]] = 1;
    rep(i, 1, n)
    {
        rep(j, 1, m + 1)
        {
            if (arr[i] == 0 || arr[i] == j)
            {
                if (j - 1 >= 1 && j - 1 <= m)
                    (dp[i][j] += dp[i - 1][j - 1]) %= MOD;
                if (j >= 1 && j <= m)
                    (dp[i][j] += dp[i - 1][j]) %= MOD;
                if (j + 1 >= 1 && j + 1 <= m)
                    (dp[i][j] += dp[i - 1][j + 1]) %= MOD;
            }
        }
    }
    ll ans = 0;
    rep(i, 1, m + 1)(ans += dp[n - 1][i]) %= MOD;
    cout << ans << endl;
}

int main()
{
    FAST;
    // int t;
    // cin >> t;
    // while (t--)
    solve();
}