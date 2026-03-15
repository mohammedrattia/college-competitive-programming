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
    T NEUTRAL_ELEMENT = {0}; // Change based on operation (0 for sum, INF for min)

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

    // Query
    ll get(ll v)
    {
        return get(v, 0, 0, size);
    }

    ll get(ll v, int x, ll lx, ll rx)
    {
        if (rx - lx == 1)
            return lx;
        ll m = (lx + rx) / 2;
        if (v - tree[2 * x + 1].value <= 0)
            return get(v, 2 * x + 1, lx, m);
        else
            return get(v - tree[2 * x + 1].value, 2 * x + 2, m, rx);
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
    ll n, h, k, sum = 0;
    cin >> n >> h >> k;
    vll arr(n), pre(n, 0);
    rep(i, 0, n)
    {
        cin >> arr[i];
    }

    pre[0] = arr[0];
    sum += arr[0];
    rep(i, 1, n)
    {
        pre[i] = pre[i - 1] + arr[i];
        sum += arr[i];
    }

    ll ans = (n + k) * (h / sum);
    h = h % sum;
    if (h == 0)
    {
        cout << ans - k << endl;
        return;
    }

    ll rem = h, idx = -1;
    while (rem > 0ll)
    {
        rem -= arr[++idx];
    }

    ll mx = -1, mxi;
    rep(i, idx, n)
    {
        if (arr[i] > mx)
        {
            mx = arr[i];
            mxi = i;
        }
    }
    SegTree<segtype> st = SegTree<segtype>(n);
    st.build(arr);

    ll mn = 1e9;
    rep(i, 0, idx + 1)
    {
        st.set(i, arr[mxi]);
        st.set(mxi, arr[i]);

        mn = min(mn, st.get(h) + 1);

        st.set(mxi, arr[mxi]);
        st.set(i, arr[i]);
    }
    cout << ans + mn << endl;
}

int main()
{
    // FAST;
    int t;
    cin >> t;
    while (t--)
        solve();
}
