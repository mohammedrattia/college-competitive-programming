// #pragma GCC optimize("O2")

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
#define rep(i, a, b) for (ll i = (a); i < (b); i++)
#define rrep(i, a, b) for (ll i = (a); i >= (b); i--)

// OTHER DEFINES
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

// SOLVE SPACE
void solve()
{
    // freopen("file.in", "r", stdin);
    // freopen("file.out", "w", stdout);
    ll n, m;
    cin >> n >> m;
    vector<pll> f(n), c(m);
    set<ll> s;
    rep(i, 0, n) { cin >> f[i].F >> f[i].S; }
    rep(i, 0, m) { cin >> c[i].F >> c[i].S; }

    sort(all(f));
    sort(all(c));

    ll last = -1;
    if (f[0].F == 1)
        last = 0;
    else if (c[0].S == 1)
        last = 1;
    else
    {
        cout << 1 << endl;
        return;
    }
    ll j = 0, k = 0, cur = 1;
    rep(i, 0, n + m)
    {
        if (last)
        {
            if (j == m || c[j].F > cur)
                break;
            if (c[j].F + c[j].S - 1 > cur)
            {
                cur = c[j].F + c[j].S - 1;
                last = 1 - last;
            }
            j++;
        }
        else
        {
            if (k == n || f[k].F > cur)
                break;
            if (f[k].F + f[k].S - 1 > cur)
            {
                cur = f[k].F + f[k].S - 1;
                last = 1 - last;
            }
            k++;
        }
    }
    cout << cur << endl;
}

int main()
{
    FAST;
    // ll t;
    // cin >> t;
    // while (t--)
    solve();
}
