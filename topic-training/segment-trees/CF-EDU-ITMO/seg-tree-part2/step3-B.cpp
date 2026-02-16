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
template <typename T>
struct SegTree
{
    int size;
    vector<T> tree;
    vector<ll> lazy;
    T NEUTRAL_ELEMENT = {0};
    ll NO_OPERATION = 0;

    // Operation functions
    T merge(T a, T b)
    {
        return {(a.value + b.value)};
    }

    void apply(int x, ll v, int len)
    {
        if (v % 2 == 1)
            tree[x].value = len - tree[x].value;
        lazy[x] += v;
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
    void modify(int l, int r)
    {
        modify(l, r, 0, 0, size);
    }

    void modify(int l, int r, int x, int lx, int rx)
    {
        if (lx >= r || rx <= l)
            return;
        if (lx >= l && rx <= r)
        {
            apply(x, 1ll, rx - lx);
            return;
        }
        propagate(x, lx, rx);
        int m = (lx + rx) / 2;
        modify(l, r, 2 * x + 1, lx, m);
        modify(l, r, 2 * x + 2, m, rx);
        tree[x] = merge(tree[2 * x + 1], tree[2 * x + 2]);
    }

    // Range Query
    int calc(int k)
    {
        return calc(k, 0, 0, size);
    }
    int calc(int k, int x, int lx, int rx)
    {
        if (rx - lx == 1 && tree[x].value)
            return lx;
        propagate(x, lx, rx);
        int m = (lx + rx) / 2;
        if (tree[2 * x + 1].value > k)
            return calc(k, 2 * x + 1, lx, m);
        else
            return calc(k - tree[2 * x + 1].value, 2 * x + 2, m, rx);
    }

    void propagate(int x, int lx, int rx)
    {
        if (lazy[x] == NO_OPERATION)
            return;
        int m = (lx + rx) / 2;
        apply(2 * x + 1, lazy[x], m - lx);
        apply(2 * x + 2, lazy[x], rx - m);

        lazy[x] = NO_OPERATION;
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
    cin >> n >> m;
    vll arr(n, 0);
    SegTree st = SegTree<segtype>(n);
    st.build(arr);
    rep(j, 0, m)
    {
        ll c;
        cin >> c;
        c--;
        if (!c)
        {
            ll l, r;
            cin >> l >> r;
            st.modify(l, r);
        }
        else
        {
            ll k;
            cin >> k;
            cout << st.calc(k) << endl;
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
