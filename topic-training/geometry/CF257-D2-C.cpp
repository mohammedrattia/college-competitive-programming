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

typedef struct
{
    ld x, y;
} point;

ld dist(point a, point b)
{
    ld x = (a.x - b.x), y = (a.y - b.y);
    return sqrt(x * x + y * y);
}

int quadrant(point a)
{
    if (a.x > 0 && a.y > 0)
        return 1;
    else if (a.x < 0 && a.y > 0)
        return 2;
    else if (a.x < 0 && a.y < 0)
        return 3;
    else if (a.x > 0 && a.y < 0)
        return 4;
    return 0;
}

// SOLVE SPACE
void solve()
{
    // freopen("file.in", "r", stdin);
    // freopen("file.out", "w", stdout);
    ll n;
    cin >> n;
    vector<point> arr(n);
    rep(i, 0, n) cin >> arr[i].x >> arr[i].y;

    vector<pair<ld, ll>> angles;
    rep(i, 0, n)
    {
        ld h = dist(arr[i], {0, 0});
        ld angle = acos(arr[i].x / h) * 180.0 / PI;
        if (arr[i].y >= 0)
            angles.push_back({angle, i});
        else if (arr[i].y < 0)
            angles.push_back({360.0-angle, i});
    }
    sort(all(angles));
    angles.push_back({angles[0].F+360, angles[0].S});
    ll idxi = -1, idxj = -1;
    ld angle = 0;
    rep(i, 0, n)
    {
        ld val = fabs(angles[i+1].F-angles[i].F);
        if (angle < val)
        {
            angle = val;
            idxi = angles[i].S;
            idxj = angles[(i+1)%n].S;
        }
    }
    cout << std::setprecision(9) << std::fixed;
    cout << 360.0-angle << endl;
}

int main()
{
    // FAST;
    // ll t;
    // cin >> t;
    // while (t--)
    solve();
}
