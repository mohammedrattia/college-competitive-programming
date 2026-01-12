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
    ll n, p, k;
    cin >> n >> p >> k;

    vector<pll> arr(n + 1);
    rep(i, 1, n + 1)
    {
        cin >> arr[i].F;
        arr[i].S = i;
    }
    sort(arr.begin() + 1, arr.end(), greater<>());

    ll s[n + 1][p];
    rep(i, 1, n + 1) rep(j, 0, p) cin >> s[i][j];

    vector<vll> dp(n + 1, vll((1 << p) + 1, -1));
    dp[0][0] = 0;

    rep(i, 1, n + 1)
    {
        ll x = arr[i].S, a = arr[i].F;
        rep(m, 0, 1 << p)
        {
            ll cnt = __builtin_popcount(m);
            ll z = (i - 1) - cnt;
            if (z < k)
            {
                if (dp[i - 1][m] != -1)
                    dp[i][m] = dp[i - 1][m] + a;
            }
            else
            {
                if (dp[i - 1][m] != -1)
                    dp[i][m] = dp[i - 1][m];
            }
            rep(j, 0, p)
            {
                if ((m & (1 << j)) && dp[i - 1][m ^ (1 << j)] != -1)
                {
                    dp[i][m] = max(dp[i][m], dp[i - 1][m ^ (1 << j)] + s[x][j]);
                }
            }
        }
    }
    cout << dp[n][(1 << p) - 1] << endl;
}

int main()
{
    FAST;
    // int t;
    // cin >> t;
    // while (t--)
    solve();
}
