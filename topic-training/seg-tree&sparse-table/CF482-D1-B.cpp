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

template <typename T>
struct SegTree
{
    int size;
    vector<T> tree;
    vector<T> lazy;
    T NEUTRAL_ELEMENT;
    T NO_OPERATION = {0};

    // Operation functions
    T merge(T a, T b)
    {
        if (a.value == NEUTRAL_ELEMENT.value)
            return b;
        else if (b.value == NEUTRAL_ELEMENT.value)
            return a;
        else if ((a.value == NEUTRAL_ELEMENT.value) && (b.value == NEUTRAL_ELEMENT.value))
            return {-1};
        return {a.value & b.value};
    }

    void apply(int x, T v, int len)
    {
        tree[x].value |= v.value;
        lazy[x].value |= v.value;
    }

    T single(ll v)
    {
        return {v};
    }

    // Constructor
    SegTree(int n)
    {
        NEUTRAL_ELEMENT = {-1};
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
    ll n, m;
    cin >> n;
    vll arr(n, 0);
    SegTree<segtype> st = SegTree<segtype>(n);
    st.build(arr);
    cin >> m;
    vll l(m), r(m), q(m);
    rep(i, 0, m)
    {
        cin >> l[i] >> r[i] >> q[i];
        l[i]--;
        st.modify(l[i], r[i], q[i]);
    }
    rep(i, 0, m)
    {
        if (st.calc(l[i], r[i]).value != q[i])
        {
            cout << "NO" << endl;
            return;
        }
    }
    cout << "YES" << endl;
    rep(i, 0, n)
    {
        cout << st.calc(i, i + 1).value << ' ';
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
