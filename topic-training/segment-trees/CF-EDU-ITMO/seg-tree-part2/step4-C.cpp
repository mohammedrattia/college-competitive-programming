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

// GRID MOVEMENT
bool is_valid(int i, int j, int n, int m) { return i < n && i >= 0 && j < m && j >= 0; }
int dx[4] = {0, 1, 0, -1};
int dy[4] = {-1, 0, 1, 0};

// RANDOMIZATION
mt19937 rnd(time(nullptr));
template <typename T>
T rng(T l, T r)
{
    return uniform_int_distribution<T>(l, r)(rnd);
}

// LAZY SEGMENT TREE
template <typename T, typename L>
struct SegTree
{
    int size;
    vector<T> tree;
    vector<L> lazy;
    T NEUTRAL_ELEMENT = {0};
    L NO_OPERATION = {-1};

    // Operation functions
    T merge(T a, T b)
    {
        return {
            a.pref,
            b.suff,
            a.seg + b.seg - (b.pref && a.suff),
            a.sum + b.sum};
    }

    void apply(int x, L v, int len)
    {
        tree[x].pref = v.value;
        tree[x].suff = v.value;
        tree[x].seg = v.value;
        tree[x].sum = v.value * len;

        lazy[x].value = v.value;
    }

    T single(ll v)
    {
        return {v == 1, v == 1, v, v};
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
    void modify(int l, int r, ll c)
    {
        modify(l, r, {c}, 0, 0, size);
    }

    void modify(int l, int r, L v, int x, int lx, int rx)
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

    void propagate(int x, int lx, int rx)
    {
        if (lazy[x].value == NO_OPERATION.value)
            return;

        int m = (lx + rx) / 2;
        apply(2 * x + 1, lazy[x], m - lx);
        apply(2 * x + 2, lazy[x], rx - m);

        lazy[x] = NO_OPERATION;
    }
};

struct segtype
{
    bool pref, suff;
    ll seg, sum;
};

struct optype
{
    ll value;
};

// SOLVE SPACE
void solve()
{
    // freopen("file.in", "r", stdin);
    // freopen("file.out", "w", stdout);
    ll n = 1e6 + 10, m;
    cin >> m;
    vll arr(n, 0);
    SegTree st = SegTree<segtype, optype>(n);
    st.build(arr);
    rep(j, 0, m)
    {
        char c;
        cin >> c;
        ll l, r;
        cin >> l >> r;
        st.modify(n / 2 + l, n / 2 + l + r, c == 'B');
        segtype ans = st.calc(0, n);
        cout << ans.seg << ' ' << ans.sum << endl;
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
