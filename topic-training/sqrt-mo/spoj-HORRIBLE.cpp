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

struct Buck
{
    ll sum, v;
};

struct SqrtDec
{
    vector<Buck> bucket;
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
        bucket = vector<Buck>(n, {0, 0});
        vals = vector<ll>(n, 0);
    }

    void build(vector<ll> arr)
    {
        vals = arr;
    }

    ll calc(int l, int r)
    {
        ll ans = 0;
        for (int i = l; i < r; i++)
        {
            if (i % root == 0 && i + root - 1 < r)
            {
                ll val = bucket[i / root].sum + bucket[i / root].v * root;
                ans += val;
                i += root - 1;
            }
            else
                ans += vals[i] + bucket[i / root].v;
        }
        return ans;
    }

    void apply(int l, int r, ll c)
    {
        for (int i = l; i < r; i++)
        {
            if (i % root == 0 && i + root - 1 < r)
            {
                bucket[i / root].v += c;
                i += root-1;
            }
            else
            {
                vals[i] += c;
                bucket[i / root].sum += c;
            }
        }
    }
};

// SOLVE SPACE
void solve()
{
    // freopen("file.in", "r", stdin);
    // freopen("file.out", "w", stdout);
    int n, q;
    cin >> n;
    cin >> q;

    SqrtDec sq = SqrtDec(n);
    rep(i, 0, q)
    {
        int t;
        ll l, r;
        cin >> t >> l >> r;
        l--;
        if (t)
        {
            cout << sq.calc(l, r) << endl;
        }
        else
        {
            ll c;
            cin >> c;
            sq.apply(l, r, c);
        }
    }
}

int main()
{
    FAST;
    ll t;
    cin >> t;
    while (t--)
        solve();
}
