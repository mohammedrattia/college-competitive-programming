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

typedef struct
{
    ld x, y;
} point;

ld dist(point a, point b)
{
    ld x = (a.x - b.x), y = (a.y - b.y);
    return sqrt(x * x + y * y);
}

ld cross(point u, point v)
{
    return u.x * v.y - u.y * v.x;
}

ld dot(point u, point v)
{
    return u.x * v.x + u.y * v.y;
}

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

point vect(point a, point b)
{
    return {b.x - a.x, b.y - a.y};
}

ld triangle_area(point a, point b, point c)
{
    return fabs(cross(vect(a, b), vect(a, c))) / 2.0;
}

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

vector<point> arr;
bool check_rect(vector<int> &p)
{
    int idx = 0, a = 0, b = 0;
    if (orientation(arr[p[0]], arr[p[1]], arr[p[2]]) != orientation(arr[p[0]], arr[p[1]], arr[p[3]]))
        idx = 1, a = 2, b = 3;
    else if (orientation(arr[p[0]], arr[p[2]], arr[p[1]]) != orientation(arr[p[0]], arr[p[2]], arr[p[3]]))
        idx = 2, a = 1, b = 3;
    else if (orientation(arr[p[0]], arr[p[3]], arr[p[1]]) != orientation(arr[p[0]], arr[p[3]], arr[p[2]]))
        idx = 3, a = 1, b = 2;
    if (idx == 0)
        return false;

    if (dist(arr[p[0]], arr[p[a]]) != dist(arr[p[idx]], arr[p[b]]) || dist(arr[p[0]], arr[p[b]]) != dist(arr[p[idx]], arr[p[a]]))
        return false;

    ld d = dot(vect(arr[p[0]], arr[p[a]]), vect(arr[p[0]], arr[p[b]]));
    if (d != 0)
        return false;
    return true;
}
bool check_square(vector<int> &p)
{
    int idx = 0, a = 0, b = 0;
    if (orientation(arr[p[0]], arr[p[1]], arr[p[2]]) != orientation(arr[p[0]], arr[p[1]], arr[p[3]]))
        idx = 1, a = 2, b = 3;
    else if (orientation(arr[p[0]], arr[p[2]], arr[p[1]]) != orientation(arr[p[0]], arr[p[2]], arr[p[3]]))
        idx = 2, a = 1, b = 3;
    else if (orientation(arr[p[0]], arr[p[3]], arr[p[1]]) != orientation(arr[p[0]], arr[p[3]], arr[p[2]]))
        idx = 3, a = 1, b = 2;
    if (idx == 0)
        return false;

    if (dist(arr[p[0]], arr[p[a]]) != dist(arr[p[idx]], arr[p[b]])
     || dist(arr[p[0]], arr[p[b]]) != dist(arr[p[idx]], arr[p[a]])
     || dist(arr[p[0]], arr[p[a]]) != dist(arr[p[idx]], arr[p[a]]))
        return false;

    if (dot(vect(arr[p[0]], arr[p[a]]), vect(arr[p[0]], arr[p[b]])) != 0)
        return false;
    return true;
}
// SOLVE SPACE
void solve()
{
    // freopen("file.in", "r", stdin);
    // freopen("file.out", "w", stdout);
    ll n = 8;
    arr = vector<point>(n);
    rep(i, 0, n) cin >> arr[i].x >> arr[i].y;
    ld ans = 0;
    for (int mask = 0; mask < (1 << n); mask++)
    {
        if (__builtin_popcount(mask) != 4)
            continue;

        vector<int> s, r;
        rep(i, 0, n)
        {
            if (mask & (1 << i))
                s.push_back(i);
            else
                r.push_back(i);
        }

        if (check_square(s) && check_rect(r))
        {
            cout << "YES" << endl;
            for (auto e : s)
                cout << e+1 << ' ';
            cout << endl;
            for (auto e : r)
                cout << e+1 << ' ';
            cout << endl;
            return;
        }
    }
    cout << "NO" << endl;
}

int main()
{
    FAST;
    // ll t;
    // cin >> t;
    // while (t--)
    solve();
}
