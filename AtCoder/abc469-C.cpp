// #pragma GCC optimize("O3,unroll-loops")

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

ll fastPower(ll a, ll p)
{
    if (p == 0)
        return 1;
    if (p == 1)
        return a;
    ll halfPower = fastPower(a, p / 2);
    ll ret = halfPower * halfPower;
    if (p % 2 == 1)
        ret *= a;
    return ret;
}

// SOLVE SPACE
void solve()
{
    // freopen("file.in", "r", stdin);
    // freopen("file.out", "w", stdout);
    ll n, m;
    cin >> n >> m;

    vll a(m), b(m);
    rep(i, 0, m) { cin >> a[i] >> b[i]; }
    bool same = true;
    ll cnta = 0, cntb = 0;
    set<ll> s;
    vector<vll> arr(n);
    rep(i, 0, m)
    {
        if (a[i] != a[0] || b[i] != b[0])
            same = false;
        if (a[i] == a[0] || b[i] == a[0])
            cnta++;
        if (a[i] == b[0] || b[i] == b[0])
            cntb++;
        s.insert(a[i]);
        s.insert(b[i]);
        arr[a[i] - 1].push_back(i);
        arr[b[i] - 1].push_back(i);
    }
    if (same)
    {
        cout << 2 * (n - 1) - 1 << endl;
        return;
    }

    if (cnta == m || cntb == m)
    {
        cout << n - (s.size() > 3) << endl;
        return;
    }

    priority_queue<pll, vector<pll>> pq;
    rep(i, 0, n)
    {
        pq.push({arr[i], i});
    }

    sort(all(vals));
    vector<pll> p;
    rep(i, 0, 4)
    {
        rep(j, i + 1, 4) { p.push_back(MP(vals[i], vals[j])); }
    }
    ll ans = 6;
    for (auto &e : p)
    {
        ll x = 0, y = 0;
        rep(i, 0, n)
        {
            if (arr[e.F - 1][x] == i)
                x++;
            else if (arr[e.S - 1][y] == i)
                y++;
            else
            {
                ans--;
                break;
            }
        }
    }
    cout << ans << endl;
}

int main()
{
    FAST;
    // ll t;
    // cin >> t;
    // while (t--)
    solve();
}
