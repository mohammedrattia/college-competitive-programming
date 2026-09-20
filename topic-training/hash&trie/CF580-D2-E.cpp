// #pragma GCC optimize("O3,unroll-loops")

#include <algorithm>
#include <array>
#include <climits>
#include <cmath>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <iomanip>
#include <iostream>
#include <map>
#include <math.h>
#include <numeric>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <string.h>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;
using namespace __gnu_pbds;

// Policy-Based Data Structures (PBDs)
template <typename K, typename V, typename Comp = less<K>>
using ordered_map = tree<K, V, Comp, rb_tree_tag, tree_order_statistics_node_update>;
template <typename K, typename Comp = less<K>> using ordered_set = ordered_map<K, null_type, Comp>;

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
#define FAST                                                                                       \
    ios_base::sync_with_stdio(false);                                                              \
    cin.tie(NULL);                                                                                 \
    cout.tie(NULL);
#define endl '\n'

// CONSTANTS
const ll INF = 1e18;
const ll MOD = 1e9 + 7;
const ll iMOD = 998244353;
const int SZ = 1e5 + 1;

const int N = 1e5 + 5, P1 = 31, P2 = 37, M = 1e9 + 7;
int pw1[N], pw2[N], inv1[N], inv2[N];
int mul(int a, int b)
{
    a = ((a % M) + M) % M;
    b = ((b % M) + M) % M;
    return (a * 1LL * b) % M;
}
int add(int a, int b)
{
    a = ((a % M) + M) % M;
    b = ((b % M) + M) % M;
    return (a + b) % M;
}
int fastPower(int base, int power)
{
    if (!power)
        return 1;
    int ret = fastPower(base, power >> 1);
    ret = mul(ret, ret);
    if (power % 2)
        ret = mul(ret, base);
    return ret;
}
void pre()
{
    pw1[0] = inv1[0] = pw2[0] = inv2[0] = 1;
    int mulInv1 = fastPower(P1, M - 2);
    int mulInv2 = fastPower(P2, M - 2);
    for (int i = 1; i < N; i++)
    {
        pw1[i] = mul(pw1[i - 1], P1);
        pw2[i] = mul(pw2[i - 1], P2);
        inv1[i] = mul(inv1[i - 1], mulInv1);
        inv2[i] = mul(inv2[i - 1], mulInv2);
    }
}
struct Hash
{
    vector<pair<int, int>> prefixHash;
    Hash(string s)
    {
        prefixHash = vector<pair<int, int>>(s.size(), {0, 0});
        for (int i = 0; i < (int)s.size(); i++)
        {
            prefixHash[i].F = mul(s[i] - '0' + 1, pw1[i]);
            prefixHash[i].S = mul(s[i] - '0' + 1, pw2[i]);
            if (i)
                prefixHash[i] = {add(prefixHash[i].F, prefixHash[i - 1].F),
                                 add(prefixHash[i].S, prefixHash[i - 1].S)};
        }
    }
    pair<int, int> getHashVal() { return prefixHash.back(); }
    pair<int, int> getRangeHashVal(int l, int r)
    {
        return {mul(add(prefixHash[r].F, -(l ? prefixHash[l - 1].F : 0)), inv1[l]),
                mul(add(prefixHash[r].S, -(l ? prefixHash[l - 1].S : 0)), inv2[l])};
    }
};
Hash *hashb;

template <typename T> struct SegTree
{
    int size;
    vector<T> tree;
    vector<T> lazy;
    T NEUTRAL_ELEMENT = {0, {0, 0}};
    T NO_OPERATION = {0, {0, 0}};

    // Operation functions
    T merge(T a, T b)
    {
        ll len = a.cnt + b.cnt;
        pii h = {add(a.hash.F, mul(b.hash.F, pw1[a.cnt])),
                 add(a.hash.S, mul(b.hash.S, pw2[a.cnt]))};
        return {len, h};
    }

    void apply(int x, T v, int len)
    {
        pii h = hashb->getRangeHashVal(0, len - 1);
        tree[x].hash = {mul(v.cnt, h.F), mul(v.cnt, h.S)};
        lazy[x].cnt = v.cnt;
    }

    T single(pii v) { return {1, v}; }

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
    void build(vector<pii> &a) { build(a, 0, 0, size); }

    void build(vector<pii> &a, int x, int lx, int rx)
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
    void modify(int l, int r, ll v) { modify(l, r, {v, {0, 0}}, 0, 0, size); }

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
        if (lazy[x].cnt == NO_OPERATION.cnt)
            return;

        int m = (lx + rx) / 2;
        apply(2 * x + 1, lazy[x], m - lx);
        apply(2 * x + 2, lazy[x], rx - m);

        lazy[x] = NO_OPERATION;
    }

    // Range Query
    T calc(int l, int r) { return calc(l, r, 0, 0, size); }
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
    ll cnt;
    pii hash;
};

// SOLVE SPACE
void solve()
{
    // freopen("file.in", "r", stdin);
    // freopen("file.out", "w", stdout);
    ll n, m, k;
    cin >> n >> m >> k;
    string str, base;
    cin >> str;
    rep(i, 0, 1e5 + 5) { base += '0'; }
    hashb = new Hash(base);

    vector<pii> arr(n);
    rep(i, 0, n) { arr[i] = {str[i] - '0' + 1, str[i] - '0' + 1}; }
    SegTree st = SegTree<segtype>(n);
    st.build(arr);

    ll q = m + k;
    while (q--)
    {
        ll c, l, r, d;
        cin >> c >> l >> r >> d;
        l--, c--;
        if (c)
        {
            pii a = st.calc(l, r - d).hash;
            pii b = st.calc(l + d, r).hash;
            if (a == b)
                cout << "YES" << endl;
            else
                cout << "NO" << endl;
        }
        else
        {
            st.modify(l, r, d + 1);
        }
    }
}

int main()
{
    FAST;
    pre();
    // ll t;
    // cin >> t;
    // while (t--)
    solve();
}
