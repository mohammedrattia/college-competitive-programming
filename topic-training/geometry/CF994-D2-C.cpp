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
    ld x = (a.x - b.x), y = (a.y - b.y);
    return sqrt(x * x + y * y);
}

ld slope(point a, point b)
{
    return (b.y - a.y) / (b.x - a.x);
}

ld y_intercept(point a, point b)
{
    ld m = slope(a, b);
    return a.y - m * a.x;
}

ld cross(point u, point v)
{
    return u.x * v.y - u.y * v.x;
}

point vect(point a, point b)
{
    return {b.x - a.x, b.y - a.y};
}

bool comp(point a, point b)
{
    if (a.x == b.x)
        return a.y > b.y;
    return a.x > b.x;
}

// SOLVE SPACE
void solve()
{
    // freopen("file.in", "r", stdin);
    // freopen("file.out", "w", stdout);
    vector<point> s(4), t(4);
    rep(i, 0, 4)
    {
        cin >> s[i].x >> s[i].y;
    }
    sort(all(s), comp);
    swap(s[2], s[3]);

    rep(i, 0, 4)
    {
        cin >> t[i].x >> t[i].y;
    }
    sort(all(t), comp);
    swap(t[0], t[1]);

    rep(i, 0, 4)
    {
        if ((t[i].x <= s[0].x && t[i].y <= s[0].y) &&
            (t[i].x <= s[1].x && t[i].y >= s[1].y) &&
            (t[i].x >= s[3].x && t[i].y <= s[3].y))
        {
            cout << "YES" << endl;
            return;
        }
    }

    rep(j, 0, 4)
    {
        ll val = 0;
        rep(i, 0, 4)
        {
            point p = vect(t[i], s[j]);
            point v = vect(t[i], t[(i + 1) % 4]);
            ld c = cross(p, v);
            ld d = dot(v, p) / dot(v, v);
            if (c > 0)
                val++;
            else if (c < 0)
                val--;
            else if ((ld)0 < d && d < (ld)1)
            {
                cout << "YES" << endl;
                return;
            }
        }
        if (abs(val) == 4)
        {
            cout << "YES" << endl;
            return;
        }
    }
    ll val1 = 0, val2 = 0;
    rep(i, 0, 4)
    {
        point p = vect(s[i], t[(i + 1) % 4]);
        point v = vect(s[i], s[(i + 1) % 4]);
        ld c = cross(p, v);
        if (c <= 0)
            val1++;
    }
    rep(i, 0, 4)
    {
        point p = vect(t[i], s[i]);
        point v = vect(t[i], t[(i + 1) % 4]);
        ld c = cross(p, v);
        if (c <= 0)
            val2++;
    }
    if (val1 == 4 && val2 == 4)
    {
        cout << "YES" << endl;
        return;
    }

    cout << "NO" << endl;
}

int main()
{
    // FAST;
    // ll t;
    // cin >> t;
    // while (t--)
    solve();
}
