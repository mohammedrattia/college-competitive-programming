#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ld long double
#define vii vector<int>
#define vll vector<ll>
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second

#define rep(i, a, b) for (ll i = (a); i < (b); i++)
#define rrep(i, a, b) for (ll i = (a); i >= (b); i--)

#define all(x) (x).begin(), (x).end()
#define PB push_back
#define MP make_pair
#define sz(x) (int)(x).size()
#define SQ(a) (a) * (a)

#define FAST                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
#define dbg(x) cout << #x << " = " << x << '\n';
#define endl '\n'
#define PI 3.14159265358979323846

const ll INF = 1e9;
const ll MOD = 1e9 + 7;
const ll SZ = 1e6;

bool is_valid(int i, int j, int n, int m) { return i >= 0 && j >= 0 && i < n && j < m; }
ll dy[4]{1, 0, -1, 0}, dx[4]{0, -1, 0, 1};

struct Point
{
    ld x, y;

    Point operator+(const Point &p) const { return {x + p.x, y + p.y}; }
    Point operator-(const Point &p) const { return {x - p.x, y - p.y}; }
    Point operator*(ld k) const { return {x * k, y * k}; }
    Point operator/(ld k) const { return {x / k, y / k}; }
};

ld angle(Point a, Point b)
{
    ld dot = a.x * b.x + a.y * b.y;
    ld len1 = hypot(a.x, a.y), len2 = hypot(b.x, b.y);
    return acos(dot / (len1 * len2));
}
// Convert degrees to radians and vice versa
ld deg_to_rad(ld deg) { return deg * PI / 180.0; }
ld rad_to_deg(ld rad) { return rad * 180.0 / PI; }

void solve()
{
    Point a, b, c, tar;
    cin >> a.x >> a.y;
    cin >> b.x >> b.y;
    cin >> c.x >> c.y;
    cin >> tar.x >> tar.y;
    bool s;
    cin >> s;
    a = a - b;
    c = c - b;
    tar = tar - b;
    b = {0, 0};
    if (s)
    {
        Point temp = a;
        a = c;
        c = temp;
    }
    ld ang1 = rad_to_deg(angle(a, c));
    ld ang2 = rad_to_deg(angle(a, tar));
    ld ang3 = rad_to_deg(angle(c, tar));
    ld e = ang1 + ang3 - ang2;
    if (e < 1e-9 || ang1 != ang1 || ang2 != ang2 || ang3 != ang3)
    {
        cout << "NO" << endl;
        return;
    }
    cout << "YES" << endl;
    cout << fixed << setprecision(10) << (s ? -1 : 1) * (ang3 * 2 - ang1) << endl;
}

int main()
{
    FAST;
    int t;
    cin >> t;
    while (t--)
        solve();
}