#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define vii vector<int>
#define vll vector<ll>
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
#define dbg(x) cout << #x << " = " << x << '\n';
#define endl '\n'
#define M_PI 3.14159265358979323846

const ll INF = 1e9;
const ll MOD = 1e9 + 7;
const ll SZ = 1e6;

bool is_valid(int i, int j, int n, int m) { return i >= 0 && j >= 0 && i < n && j < m; }
ll dy[4]{1, 0, -1, 0}, dx[4]{0, -1, 0, 1};

ll n, k;

ll dp[2][505][505];
void solve()
{
    cin >> n >> k;
    vll ans;
    dp[0][0][0] = 1;
    rep(i, 1, n + 1)
    {
        ll now = i % 2;
        ll last = 1 - now;
        ll x;
        cin >> x;
        rep(j, 0, k + 1)
        {
            rep(y, 0, j + 1)
            {
                dp[now][j][y] = dp[last][j][y];
                if (j >= x)
                {
                    dp[now][j][y] |= dp[last][j - x][y];
                    if (y >= x)
                    {
                        dp[now][j][y] |= dp[last][j - x][y - x];
                    }
                }
            }
        }
    }
    rep(i, 0, k + 1)
    {
        if (dp[n % 2][k][i])
            ans.PB(i);
    }
    cout << ans.size() << endl;
    for (ll x : ans)
        cout << x << ' ';
    cout << endl;
}

int main()
{
    FAST;
    // int t;
    // cin >> t;
    // while (t--)
    solve();
}
