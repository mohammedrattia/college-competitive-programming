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
    ll n, l, r;
    cin >> n >> l >> r;
    vll arr(n);

    ll mn = INF, idx = -1;
    rep(i, 0, n)
    {
        cin >> arr[i];
        if (i >= l && i < r && arr[i] < mn)
        {
            mn = arr[i];
            idx = i;
        }
    }
    if (idx == -1)
    {
        rep(i, 0, n)
        {
            cout << arr[i] << ' ';
        }
        cout << endl;
        return;
    }
    deque<ll> ans;
    rep(i, idx, r)
    {
        ans.push_back(arr[i]);
    }
    rep(i, l, idx)
    {
        ans.push_back(arr[i]);
    }
    bool b = true;
    idx = n;
    rep(i, 0, n)
    {
        if (i >= l && i < r) continue;
        if (arr[i] > mn)
        {
            idx = i;
            break;
        }
    }
    rrep(i, idx-1, 0)
    {
        if (i >= l && i < r) continue;
        ans.push_front(arr[i]);
    }
    rep(i, idx, n)
    {
        if (i >= l && i < r) continue;
        ans.push_back(arr[i]);
    }
    rep(i, 0, n) cout << ans[i] << ' ';
    cout << endl;
}

int main()
{
    // FAST;
    int t;
    cin >> t;
    while (t--)
        solve();
}
