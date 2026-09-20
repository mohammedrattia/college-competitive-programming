// #pragma GCC optimize("O2")

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
#define rep(i, a, b) for (ll i = (a); i < (b); i++)
#define rrep(i, a, b) for (ll i = (a); i >= (b); i--)

// OTHER DEFINES
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

ll add(ll a, ll b) { return (a % MOD + b % MOD) % MOD; }
ll mul(ll a, ll b) { return (a % MOD * b % MOD) % MOD; }

ll modPower(ll a, ll p, ll mod = MOD)
{
    if (p == 0)
        return 1;
    if (p == 1)
        return a;
    ll halfPower = modPower(a, p / 2, mod);
    ll ret = (halfPower * halfPower) % mod;
    if (p % 2 == 1)
        ret = (ret * a) % mod;
    return ret % mod;
}
ll modInverseFer(ll a, ll m = MOD) { return modPower(a, m - 2, m); }

template <typename T> struct SegTree
{
    int size;
    vector<T> tree;
    T NEUTRAL_ELEMENT = {1, 0};

    // Operation function (e.g., sum, min, max, gcd)
    T merge(T a, T b) { return {mul(a.v, b.v), add(a.p, b.p)}; }
    T single(ll v) { return {mul(100 - v, modInverseFer(100)), mul(v, modInverseFer(100 - v))}; }

    // Constructor
    SegTree(int n)
    {
        size = 1;
        while (size < n)
            size *= 2;
        tree.resize(2 * size, NEUTRAL_ELEMENT);
    }

    // Build from existing array
    void build(vector<ll> &a) { build(a, 0, 0, size); }

    void build(vector<ll> &a, int x, int lx, int rx)
    {
        if (rx - lx == 1)
        {
            if (lx < (int)a.size())
                tree[x] = single(a[lx]);
            return;
        }
        int m = (lx + rx) / 2;
        build(a, 2 * x + 1, lx, m);
        build(a, 2 * x + 2, m, rx);
        tree[x] = merge(tree[2 * x + 1], tree[2 * x + 2]);
    }

    // Point Update
    void set(int i, ll v) { set(i, v, 0, 0, size); }

    void set(int i, ll v, int x, int lx, int rx)
    {
        if (rx - lx == 1)
        {
            tree[x] = single(v);
            return;
        }
        int m = (lx + rx) / 2;
        if (i < m)
        {
            set(i, v, 2 * x + 1, lx, m);
        }
        else
        {
            set(i, v, 2 * x + 2, m, rx);
        }
        tree[x] = merge(tree[2 * x + 1], tree[2 * x + 2]);
    }

    // Range Query
    T get(int l, int r) { return get(l, r, 0, 0, size); }

    T get(int l, int r, int x, int lx, int rx)
    {
        if (lx >= r || rx <= l)
            return NEUTRAL_ELEMENT;
        if (lx >= l && rx <= r)
            return tree[x];
        int m = (lx + rx) / 2;
        T s1 = get(l, r, 2 * x + 1, lx, m);
        T s2 = get(l, r, 2 * x + 2, m, rx);
        return merge(s1, s2);
    }

    // Point Query
    T get(int i) { return get(i, 0, 0, size); }
    T get(int i, int x, int lx, int rx)
    {
        if (rx - lx == 1)
            return tree[x];
        int m = (lx + rx) / 2;
        T s;
        if (i < m)
            s = get(i, 2 * x + 1, lx, m);
        else
            s = get(i, 2 * x + 2, m, rx);
        return s;
    }
};

struct segtype
{
    ll v;
    ll p;
};

// SOLVE SPACE
void solve()
{
    // freopen("file.in", "r", stdin);
    // freopen("file.out", "w", stdout);
    ll n, q;
    cin >> n >> q;
    vll arr(n);
    rep(i, 0, n) { cin >> arr[i]; }
    SegTree st = SegTree<segtype>(n);
    st.build(arr);

    while (q--)
    {
        int c;
        cin >> c;
        c--;
        if (c)
        {
            ll x;
            cin >> x;
            segtype ans = st.get(x, n);
            cout << add(mul(ans.v, ans.p), ans.v) << endl;
        }
        else
        {
            ll x, p;
            cin >> x >> p;
            x--;
            st.set(x, p);
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
