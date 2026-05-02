// #pragma GCC optimize("O2")

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

ll xx1, yy1, xx2, yy2;
ll inside(ll x, ll y)
{
    return x >= xx1 && x <= xx2 && y <= yy1 && y >= yy2;
}
ll outside(ll x, ll y)
{
    if (x >= xx1 && x <= xx2 && (y >= yy1 || y <= yy2))
        return 1;
    else if (y <= yy1 && y >= yy2 && (x >= xx2 || x <= xx1))
        return 2;
    return 0;
}

// SOLVE SPACE
void solve()
{
    // freopen("file.in", "r", stdin);
    // freopen("file.out", "w", stdout);
    ll n;
    cin >> n;
    cin >> xx1 >> yy1 >> xx2 >> yy2;
    vll x(n), y(n);
    ll cnt = 0, dis = xx2-1, area = ((ll)abs(xx1 - xx2) + 1) * ((ll)abs(yy1 - yy2) + 1);
    rep(i, 0, n)
    {
        cin >> x[i] >> y[i];
        if (inside(x[i], y[i]))
            cnt++;
        else if (outside(x[i], y[i]) == 1)
            dis = min({dis, (ll)abs(x[i] - xx1), (ll)abs(x[i] - xx2)});
        else if (outside(x[i], y[i]) == 2)
            dis = min({dis, (ll)abs(y[i] - yy1), (ll)abs(y[i] - yy2)});
        else
        {
            dis = min(dis, (ll)abs(x[i] - xx1) + (ll)abs(y[i] - yy1));
            dis = min(dis, (ll)abs(x[i] - xx2) + (ll)abs(y[i] - yy2));
            dis = min(dis, (ll)abs(x[i] - xx1) + (ll)abs(y[i] - yy2));
            dis = min(dis, (ll)abs(x[i] - xx2) + (ll)abs(y[i] - yy1));
        }
    }
    if (cnt)
        cout << area - cnt << endl;
    else
        cout << dis + area << endl;
}

int main()
{
    // FAST;
    // int t;
    // cin >> t;
    // while (t--)
        solve();
}