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
    T NEUTRAL_ELEMENT = {-1};

    // Operation functions

    void apply(int x, T v, int len)
    {
        tree[x].value = v.value;
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
    }

    void propagate(int x, int lx, int rx)
    {
        if (tree[x].value == NEUTRAL_ELEMENT.value)
            return;
        int m = (lx + rx) / 2;
        apply(2 * x + 1, tree[x], m - lx);
        apply(2 * x + 2, tree[x], rx - m);

        tree[x] = NEUTRAL_ELEMENT;
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
            ll l, r, v;
            cin >> l >> r >> v;
            st.modify(l, r, v);
        }
        else
        {
            ll i;
            cin >> i;
            cout << (st.get(i)).value << endl;
        }
    }
    cout << endl;
}

int main()
{
    // FAST;
    // int t;
    // cin >> t;
    // while (t--)
    solve();
}
