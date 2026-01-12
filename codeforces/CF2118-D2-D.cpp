#include <iostream>
#include <string.h>
#include <string>
#include <numeric>
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

using namespace std;

#define ll long long
#define vi vector<int>
#define vll vector<long long>
#define pi pair<int, int>
#define F first
#define S second

#define rep(i, a, b) for (int i = (a); i < (b); i++)
#define rrep(i, a, b) for (int i = (a); i >= (b); i--)

#define all(x) (x).begin(), (x).end()
#define PB push_back
#define MP make_pair
#define sz(x) (int)(x).size()
#define SQ(a) (a) * (a)

#define FAST                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
#define dbg(x) cout << #x << " = " << x << '\n'
#define endl '\n'

const ll MOD = 1e9 + 7;
const int SZ = 1e6;

void solve()
{
    ll n, k, q;
    cin >> n >> k;
    ll p[n], d[n];
    rep(i, 0, n) cin >> p[i];
    rep(i, 0, n) cin >> d[i];
    cin >> q;
    while (q--)
    {
        ll pos, dir = 1;
        cin >> pos;
        ll cur = 0, x;
        x = upper_bound(p, p + n, pos) - p;
        set<tuple<ll, ll, ll>> loc;
        while (true)
        {
            if (x >= n || x < 0)
            {
                cout << "YES" << endl;
                break;
            }
            if (loc.find({cur % k, pos, dir}) != loc.end())
            {
                cout << "NO" << endl;
                break;
            }
            loc.insert({cur % k, pos, dir});
            if (cur + abs(pos - p[x]) + (k - d[x]) % k == 0)
            {
                pos = p[x];
                dir = -dir;
                x += dir;
            }
            else
            {
                pos = p[x];
                x += dir;
            }
            cur++;
        }
    }
}

int main()
{
    FAST;
    int t;
    cin >> t;
    while (t--)
        solve();
}