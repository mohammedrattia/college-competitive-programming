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

// SPARSE TABLE
struct SpaTable
{
    vector<vector<ll>> table;
    ll N, K;

    ll merge(ll a, ll b)
    {
        return gcd(a, b);
    }

    SpaTable(ll n)
    {
        K = log2_floor(n);
        N = n;
        table.resize(K + 1, vector<ll>(n));
    }

    void build(vector<ll> arr)
    {
        copy(arr.begin(), arr.end(), table[0].begin());
        for (int i = 1; i <= K; i++)
            for (int j = 0; j + (1 << i) <= N; j++)
                table[i][j] = merge(table[i - 1][j], table[i - 1][j + (1 << (i - 1))]);
    }

    ll calc(int l, int r)
    {
        ll ret = 0;
        for (int i = K; i >= 0; i--)
        {
            if ((1 << i) <= r - l + 1)
            {
                ret = merge(ret, table[i][l]);
                l += (1 << i);
            }
        }
        return ret;
    }

    ll calc_rmq(int l, int r)
    {
        int i = log2_floor(r - l + 1);
        return merge(table[i][l], table[i][r - (1 << i) + 1]);
    }

    int log2_floor(unsigned long i)
    {
        // return std::bit_width(i) - 1;
        // for pre C++20
        return i ? __builtin_clzll(1) - __builtin_clzll(i) : -1;
    }
};

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
            auto it_high = upper_bound(tree[x].vec.begin(), tree[x].vec.end(), target_x);
            return distance(it_low, it_high);
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
    ll n, m;
    cin >> n;
    vll arr(n);
    map<ll, ll> mp;
    rep(i, 0, n)
    {
        cin >> arr[i];
        mp[arr[i]]++;
    }
    SpaTable st = SpaTable(n);
    st.build(arr);
    MergeSortTree<segtype> mst = MergeSortTree<segtype>(n);
    mst.build(arr);
    cin >> m;
    rep(j, 0, m)
    {
        ll l, r;
        cin >> l >> r;
        l--, r--;
        cout << (r - l + 1) - mst.get(l, r + 1, st.calc_rmq(l, r)) << endl;
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
