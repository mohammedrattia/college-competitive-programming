#pragma GCC optimize("O3,unroll-loops")

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

struct SqrtDec
{
    vector<array<int, 101>> bucket;
    vector<int> vals;
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
        root = 1000;
        bucket = vector<array<int, 101>>(n);
    }

    void build(vector<int> arr)
    {
        vals = arr;
        for (int i = 0; i < size; i++)
        {
            for (int j = 0; j < 101; j++)
                bucket[i / root][j] = j;
        }
    }

    void apply(int l, int r, int x, int y)
    {
        if (x == y) return;
        for (int i = l; i < r; i++)
        {
            int div = i / root;
            if (i % root == 0 && i + root - 1 < r)
            {
                for (int j = 1; j <= 100; j++)
                {
                    if (bucket[div][j] == x)
                        bucket[div][j] = y;
                }
                i += root - 1;
            }
            else
            {
                for (int j = div * root; j < (div + 1) * root && j < size; j++)
                {
                    vals[j] = bucket[div][vals[j]];
                }
                for (int j = max(l, div * root); j < min(r, (div + 1) * root); j++)
                {
                    if (vals[j] == x) vals[j] = y;
                }
                for (int j = 0; j < 101; j++)
                    bucket[div][j] = j;
                i = (div + 1) * root - 1;
            }
        }
    }

    ll get(int i)
    {
        return bucket[i / root][vals[i]];
    }
};

// SOLVE SPACE
void solve()
{
    // freopen("file.in", "r", stdin);
    // freopen("file.out", "w", stdout);
    int n, q;
    cin >> n;
    vi arr(n);
    rep(i, 0, n) cin >> arr[i];

    SqrtDec sq = SqrtDec(n);
    sq.build(arr);
    cin >> q;
    rep(i, 0, q)
    {
        ll l, r, x, y;
        cin >> l >> r >> x >> y;
        l--;
        sq.apply(l, r, x, y);
    }
    rep(i, 0, n) cout << sq.get(i) << ' ';
    cout << endl;
}

int main()
{
    FAST;
    // ll t;
    // cin >> t;
    // while (t--)
    solve();
}
