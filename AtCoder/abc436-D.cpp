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

const ll INF = 1e9;
const ll MOD = 1e9 + 7;
const ll iMOD = 998244353;
const int SZ = 1e5 + 1;

bool is_valid(int i, int j, int n, int m) { return i < n && i >= 0 && j < m && j >= 0; }
int dx[4] = {0, 1, 0, -1};
int dy[4] = {-1, 0, 1, 0};

mt19937 rnd(time(nullptr));
template <typename T>
T rng(T l, T r)
{
    return uniform_int_distribution<T>(l, r)(rnd);
}

ll n, m;
vector<string> grid;
vector<vi> dis;

void solve()
{
    // freopen("file.in", "r", stdin);
    // freopen("file.out", "w", stdout);
    cin >> n >> m;
    grid = vector<string>(n);
    dis = vector<vi>(n, vi(m, -1));
    vector<vector<pll>> adj(26);
    rep(i, 0, n) cin >> grid[i];

    if (grid[0][0] == '#' || grid[n - 1][m - 1] == '#')
    {
        cout << -1 << endl;
        return;
    }

    rep(i, 0, n) rep(j, 0, m)
    {
        if (grid[i][j] >= 'a' && grid[i][j] <= 'z')
        {
            adj[grid[i][j] - 'a'].push_back({i, j});
        }
    }

    set<char> s;

    queue<pll> q;
    q.push({0, 0});
    dis[0][0] = 0;

    while (!q.empty())
    {
        pll cur = q.front();
        q.pop();
        ll a = cur.F, b = cur.S;
        if (a == n - 1 && b == m - 1)
        {
            cout << dis[a][b] << endl;
            return;
        }
        rep(i, 0, 4)
        {
            ll r = a + dx[i], c = b + dy[i];

            if (!is_valid(r, c, n, m))
                continue;

            if (grid[r][c] != '#' && (dis[r][c] > dis[a][b] + 1 || dis[r][c] == -1))
            {
                q.push({r, c});
                dis[r][c] = dis[a][b] + 1;
            }
        }
        if (grid[a][b] >= 'a' && grid[a][b] <= 'z')
        {
            if (s.count(grid[a][b]) == 0)
            {
                for (auto [i, j] : adj[grid[a][b] - 'a'])
                {
                    if (dis[i][j] > dis[a][b] + 1 || dis[i][j] == -1)
                    {
                        q.push({i, j});
                        dis[i][j] = dis[a][b] + 1;
                    }
                }
            }
            s.insert(grid[a][b]);
        }
    }
    cout << -1 << endl;
}

int main()
{
    FAST;
    // int t;
    // cin >> t;
    // while (t--)
    solve();
}
