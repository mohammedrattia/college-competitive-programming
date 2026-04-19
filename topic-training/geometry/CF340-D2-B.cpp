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

ld cross(point u, point v)
{
    return u.x * v.y - u.y * v.x;
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

int orientation(array<point, 2> segment, point p)
{
    point q = vect(segment[0], p);
    point v = vect(segment[0], segment[1]);
    ld c = cross(q, v);
    if (c < 0)
        return -1;
    else if (c > 0)
        return 1;
    else
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
    ld ans = 0;
    rep(i, 0, n)
    {
        rep(j, 0, n)
        {
            if (i == j)
                continue;

            ld area1 = -1, area2 = -1;
            int idx1 = -1, idx2 = -1;

            rep(k, 0, n)
            {
                if (k == i || k == j || orientation({arr[i], arr[j]}, arr[k]) == -1)
                    continue;
                ld val = triangle_area(arr[i], arr[j], arr[k]);
                if (area1 < val)
                {
                    area1 = val;
                    idx1 = k;
                }
            }
            rep(k, 0, n)
            {
                if (k == i || k == j || orientation({arr[i], arr[j]}, arr[k]) == 1)
                    continue;
                ld val = triangle_area(arr[i], arr[j], arr[k]);
                if (area2 < val)
                {
                    area2 = val;
                    idx2 = k;
                }
            }
            if (idx1 != -1 && idx2 != -1)
                ans = max(ans, area1 + area2);
        }
    }
    cout << std::setprecision(9) << std::fixed;
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
