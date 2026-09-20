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
const int LOG = 17;
vector<vi> adj;
vector<vi> up; // up[MAX_N][LOG]
vi depth;      // depth[MAX_N]

vi in, out, idx;
int timer = 0;

void euler_tour(int at, int prev)
{
    in[at] = timer++;
    idx[at] = in[at];
    for (int e : adj[at])
    {
        if (e != prev)
        {
            depth[e] = depth[at] + 1;
            up[e][0] = at; // a is parent of b
            for (int j = 1; j < LOG; j++)
            {
                up[e][j] = up[up[e][j - 1]][j - 1];
            }
            euler_tour(e, at);
        }
    }

    out[at] = timer;
}

struct elem
{
    int id, in, out, sz, hi;
};

bool comp(elem a, elem b) { return a.in < b.in; }

// SOLVE SPACE
void solve()
{
    // freopen("file.in", "r", stdin);
    // freopen("file.out", "w", stdout);
    ll n, q;
    cin >> n;
    adj = vector<vi>(n);
    up = vector<vi>(n, vi(LOG));
    out = in = idx = depth = vi(n);
    vi roots;

    rep(i, 0, n)
    {
        ll a;
        cin >> a;
        a--;
        if (a >= 0)
            adj[a].push_back(i);
        else
            roots.push_back(i);
    }
    for (auto i : roots)
    {
        euler_tour(i, -1);
    }
    vector<elem> elems(n);
    rep(i, 0, n) { elems[i] = {i, in[i], out[i], out[i] - in[i], depth[i]}; }
    sort(all(elems), comp);

    vector<vi> depths(n);
    rep(i, 0, n) { depths[elems[i].hi].push_back(elems[i].in); }

    cin >> q;
    rep(i, 0, q)
    {
        ll a, b;
        cin >> a >> b;
        a--;
        if (depth[a] < b)
        {
            cout << 0 << ' ';
            continue;
        }
        for (int j = LOG - 1; j >= 0; j--)
        {
            if (b & (1 << j))
                a = up[a][j];
        }
        vi &x = depths[elems[idx[a]].hi + b];
        int vals = upper_bound(x.begin(), x.end(), elems[idx[a]].out) -
                   lower_bound(x.begin(), x.end(), elems[idx[a]].in);
        cout << vals - 1 << ' ';
    }
    cout << endl;
}

int main()
{
    FAST;
    // ll t;
    // cin >> t;
    // while (t--)
    solve();
}
