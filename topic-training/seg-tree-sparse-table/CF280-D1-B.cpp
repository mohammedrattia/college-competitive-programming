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

typedef struct
{
    ll mx1, mx2, lucky;
} spatype;
struct SpaTable
{
    vector<vector<spatype>> table;
    spatype NUETRAL_ELEMENT = {0};
    ll N, K;

    spatype merge(spatype a, spatype b)
    {
        spatype res;
        if (a.mx2 > b.mx1)
            res = a;
        else if (a.mx1 < b.mx2)
            res = b;
        else
        {
            res.mx1 = max(a.mx1, b.mx1);
            res.mx2 = min(a.mx1, b.mx1);
            res.lucky = res.mx1 ^ res.mx2;
        }
        return res;
    }

    SpaTable(ll n)
    {
        K = log2_floor(n);
        N = n;
        table = vector<vector<spatype>>(K + 1, vector<spatype>(n));
    }

    spatype single(ll v)
    {
        return {v, 0, v};
    }

    void build(vector<ll> arr)
    {
        for (int i = 0; i < arr.size(); i++)
            table[0][i] = single(arr[i]);
        for (int i = 1; i <= K; i++)
            for (int j = 0; j + (1 << i) <= N; j++)
                table[i][j] = merge(table[i - 1][j], table[i - 1][j + (1 << (i - 1))]);
    }

    spatype calc(int l, int r)
    {
        spatype res = NUETRAL_ELEMENT;
        for (int i = K; i >= 0; i--)
        {
            if ((1 << i) <= r - l + 1)
            {
                res = merge(res, table[i][l]);
                l += (1 << i);
            }
        }
        return res;
    }

    spatype calc_rmq(int l, int r)
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

// SOLVE SPACE
void solve()
{
    // freopen("file.in", "r", stdin);
    // freopen("file.out", "w", stdout);
    ll n;
    cin >> n;
    vll arr(n);
    rep(i, 0, n) cin >> arr[i];

    SpaTable st = SpaTable(n);
    st.build(arr);

    ll cnt = 0, b = -1;
    rrep(k, 31, 0)
    {
        cnt = 0;
        rep(i, 0, n)
        {
            cnt += ((arr[i] & (1 << k)) != 0);
        }
        if (cnt != n && cnt != 0)
        {
            b = k;
            break;
        }
    }

    ll l = 0, r = 0, mx = 0, ans = 0;
    spatype val;
    while (r < n)
    {
        if (arr[r] & (1 << b))
        {
            while (l < r)
            {
                val = st.calc(l, r);
                ans = max(ans, val.lucky);
                l++;
            }
        }
        else if (l < r)
        {
            val = st.calc(l, r);
            ans = max(ans, val.lucky);
        }
        r++;
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
