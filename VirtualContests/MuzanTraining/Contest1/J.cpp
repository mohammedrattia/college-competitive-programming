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

ll cnt = 0;
ll n, m;
string s[7];

void dfs(ll x, ll y, ll ans)
{
    if (x == n - 1 && y == m - 1)
    {
        rep(i, 0, n - 1)
        {
            rep(j, 0, m - 1)
            {
                if (!(s[i][j] == '.' || s[i + 1][j] == '.' || s[i][j + 1] == '.' || s[i + 1][j + 1] == '.'))
                {
                    ans = 1e9;
                    return;
                }
            }
        }
        cnt = min(cnt, ans);
    }
    if (!is_valid(x, y, n, m))
        return;
    if (ans >= cnt)
        return;
    ll i = x, j = y + 1;
    if (j >= m)
    {
        i++;
        j = 0;
    }
    if (s[x][y] == '#')
    {
        s[x][y] = '.';
        dfs(i, j, ans + 1);
        s[x][y] = '#';
    }
    else
    {
        dfs(i, j, ans);
    }
}

void solve()
{
    cin >> n >> m;
    cnt = 0;
    vector<vll> vis(n, vll(m, 0));
    rep(i, 0, n)
    {
        cin >> s[i];
        rep(j, 0, m)
        {
            vis[i][j] = s[i][j] == '.';
        }
    }
    rep(i, 0, n - 1)
    {
        rep(j, 0, m - 1)
        {
            if (!(vis[i][j] || vis[i + 1][j] || vis[i][j + 1] || vis[i + 1][j + 1]))
            {
                cnt++;
                vis[i][j] = vis[i + 1][j] = vis[i][j + 1] = vis[i + 1][j + 1] = 1;
            }
        }
    }
    dfs(0, 0, 0);
    cout << cnt << endl;
}

int main()
{
    // FAST;
    int t;
    cin >> t;
    while (t--)
        solve();
}
