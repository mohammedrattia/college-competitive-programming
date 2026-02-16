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

// LAZY SEGMENT TREE
template <typename T, typename L>
struct SegTree
{
    int size;
    vector<T> tree;
    vector<L> lazy;
    T NEUTRAL_ELEMENT = {0};
    L NO_OPERATION = {0, 0};

    // Operation functions
    T merge(T a, T b)
    {
        return {a.value + b.value};
    }

    void apply(int x, L v, int len)
    {
        tree[x].value += len * (2 * v.a + (len - 1) * v.d) / 2;
        lazy[x].a += v.a;
        lazy[x].d += v.d;
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
    void modify(int l, int r, ll a, ll d)
    {
        modify(l, r, {a, d}, 0, 0, size);
    }

    void modify(int l, int r, L v, int x, int lx, int rx)
    {
        if (lx >= r || rx <= l)
            return;
        if (lx >= l && rx <= r)
        {
            apply(x, {v.a + v.d * (lx - l), v.d}, rx - lx);
            return;
        }
        propagate(x, lx, rx);
        int m = (lx + rx) / 2;
        modify(l, r, v, 2 * x + 1, lx, m);
        modify(l, r, v, 2 * x + 2, m, rx);
        tree[x] = merge(tree[2 * x + 1], tree[2 * x + 2]);
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

    void propagate(int x, int lx, int rx)
    {
        if (lazy[x].a == NO_OPERATION.a)
            return;

        int m = (lx + rx) / 2;
        apply(2 * x + 1, lazy[x], m - lx);
        apply(2 * x + 2, {lazy[x].a + lazy[x].d * (m - lx), lazy[x].d}, rx - m);

        lazy[x] = NO_OPERATION;
    }
};

struct segtype
{
    ll value;
};

struct optype
{
    ll a, d;
};

// SOLVE SPACE
void solve()
{
    // freopen("file.in", "r", stdin);
    // freopen("file.out", "w", stdout);
    ll n, m;
    cin >> n >> m;
    vll arr(n, 0);
    SegTree st = SegTree<segtype, optype>(n);
    st.build(arr);
    rep(j, 0, m)
    {
        ll c;
        cin >> c;
        c--;
        if (!c)
        {
            ll l, r, a, d;
            cin >> l >> r >> a >> d;
            l--;
            st.modify(l, r, a, d);
        }
        else
        {
            ll i;
            cin >> i;
            cout << st.get(i - 1).value << endl;
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
