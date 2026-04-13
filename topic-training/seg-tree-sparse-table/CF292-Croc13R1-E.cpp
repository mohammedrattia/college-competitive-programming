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

template <typename T>
struct SegTree
{
    int size;
    vector<T> tree;
    vector<T> lazy;
    T NEUTRAL_ELEMENT = {-1};
    T NO_OPERATION = {-1};

    // Operation functions
    T merge(T a, T b)
    {
        return {a.idx + b.idx};
    }

    void apply(int x, T v)
    {
        tree[x].idx = v.idx;
        lazy[x].idx = v.idx;
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
            apply(x, v);
            return;
        }
        propagate(x, lx, rx);
        int m = (lx + rx) / 2;
        modify(l, r, v, 2 * x + 1, lx, m);
        modify(l, r, single(v.idx + m - lx), 2 * x + 2, m, rx);
    }

    void propagate(int x, int lx, int rx)
    {
        if (lazy[x].idx == NO_OPERATION.idx)
            return;

        int m = (lx + rx) / 2;
        apply(2 * x + 1, lazy[x]);
        apply(2 * x + 2, single(lazy[x].idx + m - lx));

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
    ll idx;
};

// SOLVE SPACE
void solve()
{
    // freopen("file.in", "r", stdin);
    // freopen("file.out", "w", stdout);
    ll n, m;
    cin >> n >> m;
    vll a(n), b(n);
    rep(i, 0, n) cin >> a[i];
    rep(i, 0, n) cin >> b[i];

    SegTree<segtype> st = SegTree<segtype>(n);

    rep(i, 0, m)
    {
        ll t;
        cin >> t;
        t--;
        if (t)
        {
            ll x;
            cin >> x;
            x--;
            ll idx = st.get(x).idx;
            if (idx == -1)
                cout << b[x] << endl;
            else
                cout << a[idx] << endl;
        }
        else
        {
            ll x, y, k;
            cin >> x >> y >> k;
            x--, y--;
            st.modify(y, y + k, x - y);
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
