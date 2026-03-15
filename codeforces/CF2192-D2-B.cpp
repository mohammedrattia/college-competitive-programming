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
    ll n;
    cin >> n;
    string str;
    cin >> str;

    ll z = 0, o = 0;
    rep(i, 0, n)
    {
        z += (str[i] == '0');
        o += (str[i] == '1');
    }
    if (o == 0)
    {
        cout << 0 << endl;
    }
    else if (z == 1)
    {
        cout << 1 << endl;
        rep(i, 0, n)
        {
            if (str[i] == '0')
            {
                cout << i + 1 << ' ';
            }
        }
        cout << endl;
    }
    else if (o % 2 == 0)
    {
        cout << o << endl;
        rep(i, 0, n)
        {
            if (str[i] == '1')
            {
                cout << i + 1 << ' ';
            }
        }
        cout << endl;
    }
    else if (z % 2 != 0)
    {
        cout << z << endl;
        rep(i, 0, n)
        {
            if (str[i] == '0')
            {
                cout << i + 1 << ' ';
            }
        }
        cout << endl;
    }
    else
        cout << -1 << endl;
}

int main()
{
    // FAST;
    int t;
    cin >> t;
    while (t--)
        solve();
}
