// #pragma GCC optimize("O3,unroll-loops")

#include <iostream>
#include <string.h>
#include <string>
#include <numeric>
#include <iomanip>
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
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

// Policy-Based Data Structures (PBDs)
template <typename K, typename V, typename Comp = less<K>>
using ordered_map = tree<K, V, Comp, rb_tree_tag, tree_order_statistics_node_update>;
template <typename K, typename Comp = less<K>>
using ordered_set = ordered_map<K, null_type, Comp>;

template <typename K, typename V, typename Comp = less_equal<K>>
using ordered_multimap = tree<K, V, Comp, rb_tree_tag, tree_order_statistics_node_update>;
template <typename K, typename Comp = less_equal<K>>
using ordered_multiset = ordered_multimap<K, null_type, Comp>;

// BASIC DEFINES
#define ll long long
#define ld long double
#define vi vector<int>
#define vll vector<long long>
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second

// LOOP DEFINES
#define rep(i, a, b) for (int i = (a); i < (b); i++)
#define rrep(i, a, b) for (int i = (a); i >= (b); i--)

// OTHER DEFINES
#define PI 3.14159265358979323846
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

// BINARY LIFTING
struct Parent
{
    ll p, mx, mn;
};
const int LOG = 20;
vector<vector<pll>> adj;
vector<vector<Parent>> up; // up[MAX_N][LOG]
vi depth;                  // depth[MAX_N]

void dfs(int a, int p)
{
    for (auto [b, c] : adj[a])
    {
        if (b == p)
            continue;
        depth[b] = depth[a] + 1;
        up[b][0].p = a; // a is parent of b
        up[b][0].mn = c;
        up[b][0].mx = c;
        for (int j = 1; j < LOG; j++)
        {
            up[b][j].p = up[up[b][j - 1].p][j - 1].p;
            up[b][j].mn = min(up[up[b][j - 1].p][j - 1].mn, up[b][j - 1].mn);
            up[b][j].mx = max(up[up[b][j - 1].p][j - 1].mx, up[b][j - 1].mx);
        }
        dfs(b, a);
    }
}

// LCA
Parent get_lca(int a, int b)
{
    if (depth[a] < depth[b])
        swap(a, b);
    int k = depth[a] - depth[b];
    Parent ans = {0, 0, INF};
    for (int j = LOG - 1; j >= 0; j--)
    {
        if (k & (1 << j))
        {
            ans.mn = min(ans.mn, up[a][j].mn);
            ans.mx = max(ans.mx, up[a][j].mx);
            ans.p = up[a][j].p;
            a = up[a][j].p;
        }
    }
    if (a == b)
        return ans;
    for (int j = LOG - 1; j >= 0; j--)
    {
        if (up[a][j].p != up[b][j].p)
        {
            ans.mn = min({ans.mn, up[a][j].mn, up[b][j].mn});
            ans.mx = max({ans.mx, up[a][j].mx, up[b][j].mx});
            a = up[a][j].p;
            b = up[b][j].p;
        }
    }
    ans.p = up[a][0].p;
    ans.mn = min({ans.mn, up[a][0].mn, up[b][0].mn});
    ans.mx = max({ans.mx, up[a][0].mx, up[b][0].mx});

    return ans;
}

// SOLVE SPACE
void solve()
{
    // freopen("file.in", "r", stdin);
    // freopen("file.out", "w", stdout);
    ll n, q;
    cin >> n;
    adj = vector<vector<pll>>(n);
    up = vector<vector<Parent>>(n, vector<Parent>(LOG));
    depth = vi(n);
    rep(i, 0, n-1)
    {
        ll a, b, c;
        cin >> a >> b >> c;
        a--, b--;
        adj[a].push_back({b, c});
        adj[b].push_back({a, c});
    }
    dfs(0, 0);
    cin >> q;
    rep(i, 0, q)
    {
        ll a, b;
        cin >> a >> b;
        a--, b--;

        Parent ans = get_lca(a, b);
        cout << ans.mn << ' ' << ans.mx << endl;
    }
}

int main()
{
    FAST;
    // ll t;
    // cin >> t;
    // while (t--)
    solve();
}
