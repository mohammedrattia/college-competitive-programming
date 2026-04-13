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

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
using namespace std;

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

template <typename T>
struct SegTree
{
    int size;
    vector<T> tree;
    vector<T> lazy;
    T NEUTRAL_ELEMENT = {0};
    T NO_OPERATION = {0};

    // Operation functions
    T merge(T a, T b)
    {
        return {a.value + b.value};
    }

    void apply(int x, T v, int len)
    {
        tree[x].value += v.value * len;
        lazy[x].value += v.value;
    }

    T single(ll v)
    {
        return {v};
    }

    // Constructor
    SegTree(int n)
    {
        size = 1;
        while (size < n)
            size *= 2;
        tree.resize(2 * size, NEUTRAL_ELEMENT);
        lazy.resize(2 * size, NO_OPERATION);
    }

    // Build from existing array
    void build(vector<ll> &a)
    {
        build(a, 0, 0, size);
    }

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

    // Range Update
    void modify(int l, int r, ll v)
    {
        modify(l, r, single(v), 0, 0, size);
    }

    void modify(int l, int r, T v, int x, int lx, int rx)
    {
        if (lx >= r || rx <= l)
            return;
        if (lx >= l && rx <= r)
        {
            apply(x, v, rx - lx);
            return;
        }
        propagate(x, lx, rx);
        int m = (lx + rx) / 2;
        modify(l, r, v, 2 * x + 1, lx, m);
        modify(l, r, v, 2 * x + 2, m, rx);
        tree[x] = merge(tree[2 * x + 1], tree[2 * x + 2]);
    }

    void propagate(int x, int lx, int rx)
    {
        if (lazy[x].value == NO_OPERATION.value)
            return;

        int m = (lx + rx) / 2;
        apply(2 * x + 1, lazy[x], m - lx);
        apply(2 * x + 2, lazy[x], rx - m);

        lazy[x] = NO_OPERATION;
    }

    // Point Query
    T get(int i)
    {
        return get(i, 0, 0, size);
    }
    T get(int i, int x, int lx, int rx)
    {
        if (rx - lx == 1)
            return tree[x];
        propagate(x, lx, rx);
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
    ll value;
};

// SOLVE SPACE
void solve()
{
    // freopen("file.in", "r", stdin);
    // freopen("file.out", "w", stdout);
    ll n, m, q;
    cin >> n >> m;
    vll arr(n * m);

    rep(i, 0, n * m)
    {
        cin >> arr[i];
    }
    SegTree st = SegTree<segtype>(n * m);
    st.build(arr);

    cin >> q;
    rep(i, 0, q)
    {
        string str;
        ll x;
        cin >> str >> x;
        if (str == "red")
        {
            x--;
            st.modify(x * m, x * m + m, 1);
        }
        else
        {
            ll l = 0, r = n * m - 1;
            while (l < r)
            {
                ll u = l + (r - l) / 2;
                ll val = st.get(u).value;
                if (val < x)
                    l = u + 1;
                else if (val > x)
                    r = u - 1;
                else
                {
                    l = u;
                    break;
                }
            }
            if (st.get(l).value == x)
                cout << "YES" << endl;
            else
                cout << "NO" << endl;
        }
    }
}

int main()
{
    // FAST;
    int t;
    cin >> t;
    while (t--)
        solve();
}
