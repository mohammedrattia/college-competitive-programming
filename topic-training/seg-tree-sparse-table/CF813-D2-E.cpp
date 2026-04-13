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

struct segtype
{
    vector<ll> vec;
};

template <typename T>
struct MergeSortTree
{
    int size;
    vector<T> tree;
    T NEUTRAL_ELEMENT = {{}};

    T merge(const T &a, const T &b)
    {
        T res;
        res.vec.reserve(a.vec.size() + b.vec.size());
        std::merge(a.vec.begin(), a.vec.end(),
                   b.vec.begin(), b.vec.end(),
                   std::back_inserter(res.vec));
        return res;
    }

    T single(ll v)
    {
        return {{v}};
    }

    MergeSortTree(int n)
    {
        size = 1;
        while (size < n)
            size *= 2;
        tree.resize(2 * size, NEUTRAL_ELEMENT);
    }

    void build(const vector<ll> &a)
    {
        build(a, 0, 0, size);
    }

    void build(const vector<ll> &a, int x, int lx, int rx)
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

    int get(int l, int r, ll target_x)
    {
        return get(l, r, target_x, 0, 0, size);
    }

    int get(int l, int r, ll target_x, int x, int lx, int rx)
    {
        if (lx >= r || rx <= l)
            return 0;

        if (lx >= l && rx <= r)
        {
            auto it_low = lower_bound(tree[x].vec.begin(), tree[x].vec.end(), target_x);
            return distance(tree[x].vec.begin(), it_low);
        }

        int m = (lx + rx) / 2;
        int s1 = get(l, r, target_x, 2 * x + 1, lx, m);
        int s2 = get(l, r, target_x, 2 * x + 2, m, rx);
        return s1 + s2;
    }
};

// SOLVE SPACE
void solve()
{
    // freopen("file.in", "r", stdin);
    // freopen("file.out", "w", stdout);
    ll n, k;
    cin >> n >> k;
    vll arr(n), freq(SZ, 0), prev(n + 1);
    vector<ordered_set<ll>> val(SZ);
    vll temp(n, 1);
    rep(i, 0, n)
    {
        cin >> arr[i];
        if (freq[arr[i]] >= k)
            prev[i + 1] = *val[arr[i]].find_by_order(val[arr[i]].size() - k);
        else
            prev[i + 1] = 0;
        freq[arr[i]]++;
        val[arr[i]].insert(i + 1);
    }

    MergeSortTree<segtype> mst = MergeSortTree<segtype>(n + 1);
    mst.build(prev);

    ll q, last = 0;
    cin >> q;
    rep(i, 0, q)
    {
        ll x, y, l, r;
        cin >> x >> y;
        l = ((x + last) % n) + 1;
        r = ((y + last) % n) + 1;
        if (l > r) swap(l, r);

        last = mst.get(l, r+1, l);
        cout << last << endl;
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
