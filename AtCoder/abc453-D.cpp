// #pragma GCC optimize("O2")

#include <iostream>
#include <sstream>
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
#include <bitset>

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
const int SZ = 1e5 + 1;

int dx[4] = {0, 1, 0, -1};
int dy[4] = {-1, 0, 1, 0};
enum
{
    U,
    R,
    D,
    L
};
string dirs = "URDL";
vector<string> grid;
vector<vector<array<int, 4>>> vis;
ll g1, g2;
string ans;

int dfs(int i, int j, int last)
{
    if (i == g1 && j == g2)
        return 1;

    rep(k, 0, 4)
    {
        if (grid[i][j] == 'o' && last != k)
            continue;
        if (grid[i][j] == 'x' && last == k)
            continue;
        // if (grid[i][j] != 'x' && (last + k) % 2 == 0 && last != k)
        //     continue;
        if (!vis[i][j][k])
        {
            vis[i][j][k] = 1;
            if (dfs(i + dy[k], j + dx[k], k) == 1)
            {
                ans += dirs[k];
                return 1;
            }
        }
    }
    return 0;
}

// SOLVE SPACE
void solve()
{
    // freopen("file.in", "r", stdin);
    // freopen("file.out", "w", stdout);
    ll n, m;
    cin >> n >> m;
    grid = vector<string>(n);
    vis = vector<vector<array<int, 4>>>(n, vector<array<int, 4>>(m, {0, 0, 0, 0}));

    ll x, y;
    rep(i, 0, n)
    {
        cin >> grid[i];
        rep(j, 0, m)
        {
            if (grid[i][j] == 'S')
            {
                x = i;
                y = j;
            }
            if (grid[i][j] == 'G')
            {
                g1 = i;
                g2 = j;
            }
            if (grid[i][j] == '#' || i == 0)
                vis[i][j][U] = 1;
            if (grid[i][j] == '#' || j == 0)
                vis[i][j][L] = 1;
            if (grid[i][j] == '#' || i == n - 1)
                vis[i][j][D] = 1;
            if (grid[i][j] == '#' || j == m - 1)
                vis[i][j][R] = 1;
        }
    }
    dfs(x, y, '?');
    reverse(all(ans));
    if (ans != "")
        cout << "Yes\n"
             << ans << endl;
    else
        cout << "No" << endl;
}

int main()
{
    // FAST;
    // int t;
    // cin >> t;
    // while (t--)
    solve();
}
