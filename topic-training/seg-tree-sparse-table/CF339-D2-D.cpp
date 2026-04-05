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
    T NEUTRAL_ELEMENT;

    // Operation functions
    T merge(T a, T b)
    {
        if (a.p)
            return {a.value ^ b.value, !a.p};
        return {a.value | b.value, !a.p};
    }

    T single(ll v)
    {
        return {v, 0};
    }

    // Constructor
    SegTree(int n)
    {
        NEUTRAL_ELEMENT = {-1};
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
        tree[x] = merge(tree[2 * x + 1], tree[2 * x + 2]);
    }

    // Range Update
    void modify(int i, ll v)
    {
        modify(i, single(v), 0, 0, size);
    }

    void modify(int i, T v, int x, int lx, int rx)
    {
        if (rx - lx == 1)
        {
            tree[x] = v;
            return;
        }
        int m = (lx + rx) / 2;
        if (i < m)
            modify(i, v, 2 * x + 1, lx, m);
        else
            modify(i, v, 2 * x + 2, m, rx);
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
        int m = (lx + rx) / 2;
        T s1 = calc(l, r, 2 * x + 1, lx, m);
        T s2 = calc(l, r, 2 * x + 2, m, rx);
        return merge(s1, s2);
    }
};

struct segtype
{
    ll value, p;
};

// SOLVE SPACE
void solve()
{
    // freopen("file.in", "r", stdin);
    // freopen("file.out", "w", stdout);
    ll n, m;
    cin >> n;
    cin >> m;

    vll arr(1ll << n, 0);
    rep(i, 0, 1ll << n) cin >> arr[i];
    SegTree<segtype> st = SegTree<segtype>(1ll << n);
    st.build(arr);

    rep(i, 0, m)
    {
        ll k, v;
        cin >> k >> v;
        k--;
        st.modify(k, v);
        cout << st.tree[0].value << endl;
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
