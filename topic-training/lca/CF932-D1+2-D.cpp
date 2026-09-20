#pragma GCC optimize("O3,unroll-loops")

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

// BINARY LIFTING
const int SQRT = 1000;
// vector<vi> adj;
// vector<vi> up; // up[MAX_N][LOG]
// vi depth;      // depth[MAX_N]

// SOLVE SPACE
void solve()
{
    // freopen("file.in", "r", stdin);
    // freopen("file.out", "w", stdout);
    ll q;
    cin >> q;
    vll parent, weight, dp, tot, seqp, seqgp;
    int cnt = 0;
    weight = tot = vll(q, 0);
    parent = seqp = seqgp = vll(q, -1);
    dp = vll(q, 1);

    ll last = 0;
    rep(i, 0, q)
    {
        ll c, a, b;
        cin >> c >> a >> b;
        ll r = a ^ last, w = b ^ last;
        r--;
        if (c == 1)
        {
            cnt++;
            parent[cnt] = r;
            weight[cnt] = w;
            tot[cnt] = w;
            ll x = r;
            while (x != -1 && weight[x] < w)
            {
                x = seqp[x];
            }
            if (x == -1)
                continue;
            seqp[cnt] = x;
            dp[cnt] = dp[x] + 1;
            tot[cnt] = tot[x] + w;
            if (dp[cnt] % SQRT == 0)
                seqgp[cnt] = parent[cnt];
            else
                seqgp[cnt] = seqgp[x];
        }
        else
        {
            if (weight[r] > w)
            {
                last = 0;
                cout << last << endl;
                continue;
            }
            ll x = r;
            while (seqgp[x] != -1 && tot[r] - tot[seqgp[x]] <= w)
            {
                x = seqgp[x];
            }
            while (x != -1 && tot[r] - tot[max(0ll, seqp[x])] <= w)
            {
                x = seqp[x];
            }
            last = dp[r];
            if (x != -1)
                last -= dp[x];
            cout << last << endl;
        }
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
