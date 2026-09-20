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

// GEOMETRY
typedef struct
{
    ld x, y;
} point;
ld dist(point a, point b)
{
    ld x = (a.x - b.x), y = (a.y - b.y);
    return sqrt(x * x + y * y);
}
bool comp(point a, point b)
{
    if (a.x == b.x)
        return a.y > b.y;
    return a.x > b.x;
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

// lines
typedef struct
{
    ld a, b, c;
} line;
ld slope(point a, point b) { return (b.y - a.y) / (b.x - a.x); }
ld y_intercept(point a, point b)
{
    ld m = slope(a, b);
    return a.y - m * a.x;
}
point line_intersection(line l1, line l2)
{
    return {(l1.b * l2.c - l2.b * l1.c) / (l1.a * l2.b - l2.a * l1.b),
            (l1.c * l2.a - l2.c * l1.a) / (l1.a * l2.b - l2.a * l1.b)};
}

line get_line(point p1, point p2) // a*x + b*y + c = 0 (b*y - b*k - ax = ax)
{
    ld a = p2.y - p1.y, b = p1.x - p2.x;
    ld c = a * p1.x + b * p1.y;
    return {a, b, -c};
}

// vectors
ld dot(point u, point v) { return u.x * v.x + u.y * v.y; }
ld cross(point u, point v) { return u.x * v.y - u.y * v.x; }
point vect(point a, point b) { return {b.x - a.x, b.y - a.y}; }
int orientation(point a, point b, point p)
{
    point q = vect(a, p);
    point v = vect(a, b);
    ld c = cross(q, v);
    if (c < 0)
        return -1;
    else if (c > 0)
        return 1;
    else
        return 0;
}

// areas
ld triangle_area(point a, point b, point c) { return fabs(cross(vect(a, b), vect(a, c))) / 2.0; }
ld sheolace(vector<point> arr)
{
    ld area = 0;
    int n = arr.size();
    for (int i = 0; i < n; i++)
    {
        area += cross(arr[i], arr[(i + 1) % n]);
    }
    return fabs(area) / 2.0;
}

// SOLVE SPACE
void solve()
{
    // freopen("file.in", "r", stdin);
    // freopen("file.out", "w", stdout);
    ll n;
    cin >> n;
}

int main()
{
    // FAST;
    // ll t;
    // cin >> t;
    // while (t--)
    solve();
}
