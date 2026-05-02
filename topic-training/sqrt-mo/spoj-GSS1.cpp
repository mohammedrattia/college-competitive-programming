// #pragma GCC optimize("O3,unroll-loops")

#include <iostream>
#include <string.h>
#include <string>
#include <numeric>
#include <iomanip>
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

// Policy-Based Data Structures (PBDs)
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

struct sqrttype
{
    ll sum, pref, suff, seg;
};

struct SqrtDec
{
    vector<sqrttype> bucket;
    vector<ll> vals;
    int root;
    int size;
    const ll NEUTRAL = INF;

    ll merge(ll a, ll b)
    {
        return min(a, b);
    }

    SqrtDec(int n)
    {
        size = n;
        root = sqrt(n);
        bucket = vector<sqrttype>(n, {0, -INF, -INF, -INF});
    }

    void build(vector<ll> arr)
    {
        vals = arr;
        for (int i = 0; i < size; i++)
        {
            bucket[i / root].seg = max(max(bucket[i / root].seg, vals[i]), vals[i] + bucket[i / root].suff);
            bucket[i / root].pref = max(bucket[i / root].pref, bucket[i / root].sum + vals[i]);
            bucket[i / root].suff = max(vals[i], vals[i] + bucket[i / root].suff);
            bucket[i / root].sum += vals[i];
        }
    }

    ll calc(int l, int r)
    {
        sqrttype ans = {-INF, -INF, -INF, -INF};
        for (int i = l; i < r; i++)
        {
            if (i % root == 0 && i + root - 1 < r)
            {
                ans.seg = max(max(ans.seg, bucket[i / root].seg), bucket[i / root].pref + ans.suff);
                ans.pref = max(ans.pref, ans.sum + bucket[i / root].pref);
                ans.suff = max(bucket[i / root].suff, bucket[i / root].sum + ans.suff);
                ans.sum += bucket[i / root].sum;
                i += root - 1;
            }
            else
            {
                ans.seg = max(max(ans.seg, vals[i]), vals[i] + ans.suff);
                ans.pref = max(ans.pref, ans.sum + vals[i]);
                ans.suff = max(vals[i], vals[i] + ans.suff);
                ans.sum += vals[i];
            }
        }
        return ans.seg;
    }
};

// SOLVE SPACE
void solve()
{
    // freopen("file.in", "r", stdin);
    // freopen("file.out", "w", stdout);
    int n, q;
    cin >> n;
    vll arr(n);
    rep(i, 0, n) cin >> arr[i];

    SqrtDec sq = SqrtDec(n);
    sq.build(arr);
    cin >> q;
    rep(i, 0, q)
    {
        ll l, r;
        cin >> l >> r;
        l--;
        cout << sq.calc(l, r) << endl;
    }
}

int main()
{
    FAST;
    // ll t;
    // cin >> t;
    // while (t--)
    solve();
}
