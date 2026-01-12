#include <bits/stdc++.h>

using namespace std;

#define ll long long
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
#define M_PI 3.14159265358979323846

const ll INF = 1e9;
const ll MOD = 1e9 + 7;
const ll SZ = 1e6;

bool is_valid(int i, int j, int n, int m) { return i >= 0 && j >= 0 && i < n && i < m; }

void solve()
{
    double x1, y1, r1, x2, y2, r2;
    cin >> x1 >> y1 >> r1;
    cin >> x2 >> y2 >> r2;

    double d = sqrt(SQ(abs(x1 - x2)) + SQ(abs(y1 - y2)));
    double c1 = SQ(r1) * M_PI;
    double c2 = SQ(r2) * M_PI;

    if (d >= r1 + r2 || max(r1, r2) > d + min(r1, r2) || (x1 == x2 && y1 == y2))
    {
        cout << -1 << endl;
        return;
    }
    if (max(r1, r2) == d + min(r1, r2))
    {
        cout << fixed << setprecision(20) << c1 - c2 << endl;
        return;
    }
    double p = sqrt(SQ(abs(min(r1, r2))) + SQ(abs(d)));
    double s = (r1 + r2 + d) / 2;
    double area_tri = sqrt(s * (s - r1) * (s - r2) * (s - d));
    double b = area_tri * 4 / d;
    double a1 = asin((b / 2) / r1) * 2;
    double a2 = asin((b / 2) / r2) * 2;
    if (r1 > p)
    {
        a2 = (M_PI - asin((b / 2) / r1)) * 2;
    }
    else if (r2 > p)
    {
        a1 = (M_PI - asin((b / 2) / r2)) * 2;
    }
    double s1 = (a1 / (M_PI * 2)) * c1;
    double s2 = (a2 / (M_PI * 2)) * c2;

    double area = s1 + s2 - b * d / 2;
    cout << fixed << setprecision(10) << max(c1 - area, c2 - area) << endl;
}

int main()
{
    FAST;
    // int t;
    // cin >> t;
    // while (t--)
    solve();
}