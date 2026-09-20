// #pragma GCC optimize("O3,unroll-loops")

#include <algorithm>
#include <array>
#include <climits>
#include <cmath>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <iomanip>
#include <iostream>
#include <map>
#include <math.h>
#include <numeric>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <string.h>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;
using namespace __gnu_pbds;

// Policy-Based Data Structures (PBDs)
template <typename K, typename V, typename Comp = less<K>>
using ordered_map = tree<K, V, Comp, rb_tree_tag, tree_order_statistics_node_update>;
template <typename K, typename Comp = less<K>> using ordered_set = ordered_map<K, null_type, Comp>;

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
#define FAST                                                                                       \
    ios_base::sync_with_stdio(false);                                                              \
    cin.tie(NULL);                                                                                 \
    cout.tie(NULL);
#define endl '\n'

// CONSTANTS
const ll INF = 1e18;
const ll MOD = 1e9 + 7;
const ll iMOD = 998244353;
const int SZ = 1e5 + 1;

// BINARY LIFTING
const int LOG = 20;
vector<vi> adj;
vector<vi> up; // up[MAX_N][LOG]
vi depth;      // depth[MAX_N]

void dfs(int a, int p)
{
    for (int b : adj[a])
    {
        if (b == p)
            continue;
        depth[b] = depth[a] + 1;
        up[b][0] = a; // a is parent of b
        for (int j = 1; j < LOG; j++)
        {
            up[b][j] = up[up[b][j - 1]][j - 1];
        }
        dfs(b, a);
    }
}

// LCA
int get_lca(int a, int b)
{
    if (depth[a] < depth[b])
        swap(a, b);
    int k = depth[a] - depth[b];
    for (int j = LOG - 1; j >= 0; j--)
    {
        if (k & (1 << j))
            a = up[a][j];
    }
    if (a == b)
        return a;
    for (int j = LOG - 1; j >= 0; j--)
    {
        if (up[a][j] != up[b][j])
        {
            a = up[a][j];
            b = up[b][j];
        }
    }
    return up[a][0];
}

ll dist(ll a, ll b)
{
    ll v = get_lca(a, b);
    ll d = depth[a] - depth[v] + depth[b] - depth[v] + 1;
    return d;
}

// SOLVE SPACE
void solve()
{
    // freopen("file.in", "r", stdin);
    // freopen("file.out", "w", stdout);
    ll n, q;
    cin >> n;
    adj = vector<vi>(n);
    up = vector<vi>(n, vi(LOG));
    depth = vi(n);
    rep(i, 1, n)
    {
        ll a, b;
        cin >> a >> b;
        a--, b--;
        adj[b].push_back(a);
        adj[a].push_back(b);
    }
    dfs(0, 0);
    cin >> q;
    rep(i, 0, q)
    {
        ll k;
        cin >> k;
        vector<pll> arr(k);
        rep(j, 0, k)
        {
            cin >> arr[j].S;
            arr[j].S--;
            arr[j].F = depth[arr[j].S];
        }
        sort(all(arr));
        bool line = true;
        ll lca = -1;
        rep(i, 1, k)
        {
            if (get_lca(arr[i - 1].S, arr[i].S) != arr[i - 1].S)
            {
                line = false;
                lca = get_lca(arr[i - 1].S, arr[i].S);
                break;
            }
        }
        if (line)
        {
            cout << "YES" << endl;
            continue;
        }
        else
        {
            bool bad = false;
            queue<ll> qu;
            int idx = (lca == arr[0].S);
            ll last = arr[idx].S;
            rep(i, idx + 1, k)
            {
                if (depth[last] <= depth[lca])
                {
                    bad = true;
                    break;
                }
                ll x = get_lca(last, arr[i].S);
                if (x != last)
                {
                    if (x != lca)
                    {
                        bad = true;
                        break;
                    }
                    else
                        qu.push(arr[i].S);
                }
                else
                    last = arr[i].S;
            }
            if (bad)
            {
                cout << "NO" << endl;
                continue;
            }
            if (qu.size() <= 1)
            {
                cout << "YES" << endl;
                continue;
            }
            last = qu.front();
            qu.pop();
            while(!qu.empty())
            {
                ll x = get_lca(last, qu.front());
                if (x != last)
                {
                    bad = true;
                    break;
                }
                last = qu.front();
                qu.pop();
            }
            if (bad)
            {
                cout << "NO" << endl;
                continue;
            }
            else
            {
                cout << "YES" << endl;
            }
        }
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
