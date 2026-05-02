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
const int SZ = 2e5 + 1;

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

    // Range Query
    T calc(int l, int r)
    {
        return calc(l, r, 0, 0, size);
    }
    T calc(int l, int r, int x, int lx, int rx)
    {
        if (lx >= r || rx <= l)
            return NEUTRAL_ELEMENT;
        if (lx >= l && rx <= r)
            return tree[x];
        propagate(x, lx, rx);
        int m = (lx + rx) / 2;
        T s1 = calc(l, r, 2 * x + 1, lx, m);
        T s2 = calc(l, r, 2 * x + 2, m, rx);
        return merge(s1, s2);
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
    ll n, q;
    cin >> n;
    vll arr(n), mv(n);
    rep(i, 0, n)
    {
        cin >> arr[i];
    }
    ll moving = 0, mn = INF;
    rrep(i, n - 1, 0)
    {
        mv[i] = max(arr[i] - mn, 0ll);
        moving += mv[i];
        mn = min(mn, arr[i]);
    }
    stack<int> st;
    rep(i, 1, n)
    {
        if (arr[i] <= arr[i - 1] && (i == n - 1 || arr[i] <= arr[i + 1]))
        {
            while (!st.empty() && arr[st.top()] >= arr[i])
            {
                st.pop();
            }
            st.push(i);
        }
    }
    ll ans = 0, l = -1, r = -1;
    while (!st.empty())
    {
        int cur = st.top(), idx = -1;
        st.pop();
        rrep(i, cur, 0)
        {
            if (arr[i] < arr[cur])
            {
                idx = i;
                break;
            }
        }
        if (ans < cur - idx - 1ll)
        {
            ans = cur - idx - 1ll;
            l = idx + 1;
            r = cur;
        }
    }
    if (l != -1)
    {
        arr[r]--;
        rep(i, l, r)
        {
            mv[i]++;
        }
    }
    SegTree seg = SegTree<segtype>(SZ);

    ll dist = 0;
    rrep(i, n - 1, 0)
    {
        dist += mv[i] * (n - i - 1) - seg.calc(arr[i] - mv[i], arr[i]).value;
        seg.modify(0, arr[i], 1);
    }
    cout << dist << endl;
}

int main()
{
    FAST;
    ll t;
    cin >> t;
    while (t--)
        solve();
}
