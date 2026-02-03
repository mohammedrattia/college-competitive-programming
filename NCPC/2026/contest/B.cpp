// #pragma GCC optimize("O2")

#include <iostream>
#include <iomanip>
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
ll fastPower(ll a, ll p)
{
    if (p == 0)
        return 1;
    if (p == 1)
        return a;
    ll halfPower = fastPower(a, p / 2);
    ll ret = halfPower * halfPower;
    if (p % 2 == 1)
        ret *= a;
    return ret;
}
ll createSmallNum(ll cnt)
{
    ll num = 0;
    while (cnt--)
    {
        num *= 10;
        num++;
    }
    return num;
}
void solve()
{
    // freopen("file.in", "r", stdin);
    // freopen("file.out", "w", stdout);
    ll n, x;
    cin >> n >> x;
    ll num = n, k, val, last = 0, i = 0, ans = 0, cnt = 0;
    while (num)
    {
        k = num % 10ll;
        if (k == 0)
        {
            val = (createSmallNum(cnt + 1) - last);
            if (n + val > x)
                break;
            ans = val;
        }
        last += k * fastPower(10, cnt);
        cnt++;
        num /= 10ll;
    }
    if (n == 0 && x)
        cout << 1 << endl;
    else
        cout << ans << endl;
}

int main()
{
    // FAST;
    int t;
    cin >> t;
    while (t--)
        solve();
}
