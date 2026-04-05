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
    ll n, m;
    cin >> n >> m;
    if (n > m || (n == 0 && m%2==0))
    {
        cout << "NO" << endl;
        return;
    }

    int node = n + m;
    if ((m - n) % 2 != 0)
    {
        cout << "YES" << endl;
        rep(i, 0, 2*n-1)
        {
            cout << node - 1 << ' ' << node << endl;
            node--;
        }
        rep(i, 0, m - n)
        {
            if (node == 1) break;
            cout << 1 << ' ' << node-- << endl;
        }
        cout << endl;
    }
    else
    {
        int node = 1;
        cout << "YES" << endl;
        rep(i, 0, 2*n-1)
        {
            cout << node << ' ' << node+1 << endl;
            node++;
        }
        ll val = node++;
        rep(i, 0, m - n)
        {
            if (node > n+m) break;
            cout << val << ' ' << node++ << endl;
        }
        cout << endl;
    }
}

int main()
{
    // FAST;
    int t;
    cin >> t;
    while (t--)
        solve();
}
