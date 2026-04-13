// #pragma GCC optimize("O2")

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
void solve()
{
    // freopen("file.in", "r", stdin);
    // freopen("file.out", "w", stdout);
    ll n, k;
    cin >> n >> k;
    vll arr(n), special(k);
    rep(i, 0, n) cin >> arr[i];
    rep(i, 0, k) cin >> special[i];

    ll cnt_r = 1, cnt_l = 1;
    ll v = special[0]-1;
    ll last = arr[v];
    rep(i, v, n)
    {
        if (arr[i] != last)
        {
            cnt_r++;
        }
        last = arr[i];
    }
    if (last == arr[v]) cnt_r--;

    last = arr[v];
    rrep(i, v, 0)
    {
        if (arr[i] != last)
        {
            cnt_l++;
        }
        last = arr[i];
    }
    if (last == arr[v]) cnt_l--;
    cout << max(cnt_l, cnt_r) << endl;
}

int main()
{
    // FAST;
    int t;
    cin >> t;
    while (t--)
        solve();
}
