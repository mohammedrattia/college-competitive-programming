// #pragma GCC optimize("O2")

#include <iostream>
#include <sstream>
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
#include <random>
#include <bitset>

using namespace std;

// BASIC DEFINES
#define ll long long
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

// SOLVE SPACE
void solve()
{
    // freopen("file.in", "r", stdin);
    // freopen("file.out", "w", stdout);
    ll n;
    cin >> n;
    vll arr(n);
    rep(i, 0, n) cin >> arr[i];
    ll ans = 0;
    for (ll mask = 0; mask < (1 << n); mask++)
    {
        ll cnt = 0;
        double last = 0.5;
        rep(i, 0, n)
        {
            double sign = ((mask & (1<<i)) != 0 ? 1 : -1);
            double v = last + sign*arr[i];
            if ((last > 0 && v < 0) || (last < 0 && v > 0))
                cnt++;
            last += sign*arr[i];
        }
        ans = max(ans, cnt);
    }
    cout << ans << endl;
}

int main()
{
    // FAST;
    // int t;
    // cin >> t;
    // while (t--)
        solve();
}
