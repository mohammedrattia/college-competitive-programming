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

typedef struct
{
    ld x, y;
} point;

ld dot(point u, point v)
{
    return u.x * v.x + u.y * v.y;
}
ld dist(point a, point b)
{
    return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

// SOLVE SPACE
void solve(ld xx, ld yy, ll nn)
{
    // freopen("file.in", "r", stdin);
    // freopen("file.out", "w", stdout);
    point m = {xx, yy};
    ll n = nn;
    vector<point> arr(n + 1);
    rep(i, 0, n + 1)
    {
        cin >> arr[i].x >> arr[i].y;
    }
    point ans;
    ld mn = INF;
    rep(i, 0, n)
    {
        point p = {m.x - arr[i].x, m.y - arr[i].y};
        point v = {arr[i + 1].x - arr[i].x, arr[i + 1].y - arr[i].y};
        if (dot(v, v) != 0)
        {
            ld val = dot(v, p) / dot(v, v);
            point u = {val * v.x, val * v.y};
            u = {u.x + arr[i].x, u.y + arr[i].y};
            if (0 < val && val < (ld)1)
            {
                if (dist(m, u) < mn)
                {
                    mn = dist(m, u);
                    ans = u;
                }
            }
        }
        if (dist(m, arr[i]) < mn)
        {
            mn = dist(m, arr[i]);
            ans = arr[i];
        }
        if (dist(m, arr[i + 1]) < mn)
        {
            mn = dist(m, arr[i + 1]);
            ans = arr[i + 1];
        }
    }
    cout << std::setprecision(4) << std::fixed;
    cout << ans.x << endl;
    cout << ans.y << endl;
}

int main()
{
    // FAST;
    ld x, y;
    ll n;
    while (cin >> x >> y >> n)
        solve(x, y, n);
}
