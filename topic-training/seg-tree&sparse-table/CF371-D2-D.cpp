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

// SEGMENT TREE
template <typename T>
struct SegTree
{
    int size;
    vector<T> tree;
    vector<T> lazy;
    T NEUTRAL_ELEMENT = {0, 0};
    T NO_OPERATION = {0};

    // Operation functions
    T merge(T a, T b)
    {
        return {a.value + b.value, a.cap + b.cap};
    }

    void apply(int x, ll v, int len)
    {
        tree[x].value += v;
        lazy[x].value += v;
    }

    T single(ll v)
    {
        return {0, v};
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
        modify(l, r, v, 0, 0, size);
    }

    void modify(int l, int r, ll &v, int x, int lx, int rx)
    {
        if (lx >= r || rx <= l || v <= 0)
            return;
        if (lx >= l && rx <= r)
        {
            ll val = min(tree[x].cap - tree[x].value, v);
            apply(x, val, rx - lx);
            v -= val;
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
        ll c = tree[2 * x + 1].cap, v = tree[2 * x + 1].value;
        apply(2 * x + 1, min(c - v, lazy[x].value), m - lx);
        apply(2 * x + 2, max(0ll, lazy[x].value - (c - v)), rx - m);

        lazy[x] = NO_OPERATION;
    }

    // Range Query
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
    ll value, cap;
};

// SOLVE SPACE
void solve()
{
    // freopen("file.in", "r", stdin);
    // freopen("file.out", "w", stdout);
    ll n, m;
    cin >> n;

    vll arr(n);
    rep(i, 0, n) cin >> arr[i];
    SegTree<segtype> st = SegTree<segtype>(n);
    st.build(arr);

    cin >> m;
    rep(i, 0, m)
    {
        ll c;
        cin >> c;
        c--;
        if (!c)
        {
            ll k, v;
            cin >> k >> v;
            k--;
            st.modify(k, n, v);
        }
        else
        {
            ll k;
            cin >> k;
            k--;
            cout << st.get(k).value << endl;
        }
    }
}

int main()
{
    // FAST;
    // int t;
    // cin >> t;
    // while (t--)
    solve();
}
