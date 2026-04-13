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
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

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
    T NEUTRAL_ELEMENT = {0};

    // Operation function (e.g., sum, min, max, gcd)
    T merge(T a, T b)
    {
        return {a.value + b.value};
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
        tree[x] = merge(tree[2 * x + 1], tree[2 * x + 2]);
    }

    // Point Update
    void set(int i, ll v)
    {
        set(i, v, 0, 0, size);
    }

    void set(int i, ll v, int x, int lx, int rx)
    {
        if (rx - lx == 1)
        {
            tree[x] = single(v);
            return;
        }
        int m = (lx + rx) / 2;
        if (i < m)
        {
            set(i, v, 2 * x + 1, lx, m);
        }
        else
        {
            set(i, v, 2 * x + 2, m, rx);
        }
        tree[x] = merge(tree[2 * x + 1], tree[2 * x + 2]);
    }

    // Range Query
    T get(int l, int r)
    {
        return get(l, r, 0, 0, size);
    }

    T get(int l, int r, int x, int lx, int rx)
    {
        if (lx >= r || rx <= l)
            return NEUTRAL_ELEMENT;
        if (lx >= l && rx <= r)
            return tree[x];
        int m = (lx + rx) / 2;
        T s1 = get(l, r, 2 * x + 1, lx, m);
        T s2 = get(l, r, 2 * x + 2, m, rx);
        return merge(s1, s2);
    }
};

struct segtype
{
    ll value;
};

bool comp(array<ll, 3> a, array<ll, 3> b)
{
    if (a[0] == b[0])
        return a[2] < b[2];
    return a[0] < b[0];
}

// SOLVE SPACE
void solve()
{
    // freopen("file.in", "r", stdin);
    // freopen("file.out", "w", stdout);
    ll n;
    cin >> n;
    vector<array<ll, 3>> arr(n);
    vll temp(n, 1);
    rep(i, 0, n)
    {
        cin >> arr[i][0];
        arr[i][1] = i;
        arr[i][2] = -1;
    }
    sort(all(arr));

    array<ll, 3> k = arr[0];
    ll idx = 0;
    rep(i, 0, n)
    {
        if (k[0] != arr[i][0])
        {
            ll j = i;
            while (j < n && arr[i][0] == arr[j][0])
            {
                if (k[1] < arr[j][1])
                {
                    arr[j][2] = idx++;
                    k = arr[j];
                }
                j++;
            }
        }
        if (arr[i][2] != -1)
            continue;
        arr[i][2] = idx++;
        k = arr[i];
    }
    sort(all(arr), comp);

    SegTree st = SegTree<segtype>(n);
    st.build(temp);

    ll ans = 0, last = 0;
    rep(i, 0, n)
    {
        if (last > arr[i][1])
        {
            ans += st.get(last, n).value;
            last = 0;
        }
        ans += st.get(last, arr[i][1] + 1).value;
        last = arr[i][1];
        st.set(arr[i][1], 0);
    }

    cout << ans << endl;
}

int main()
{
    // FAST;
    // int t;
    // cin >> t;
    // while (t--)
    solve();
}
