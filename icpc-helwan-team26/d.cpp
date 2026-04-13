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
    ll n, m, k;
    cin >> n >> m >> k;
    string s, t;
    string s1, t1;
    cin >> s >> t;
    ll cnt = k;
    rep(i, 0, n)
    {
        if (s[i] == '#' && cnt)
        {
            cnt--;
        }
        else
        {
            if (s[i] != '#')
                cnt = k;
            s1 += s[i];
        }
    }
    cnt = k;
    rep(i, 0, m)
    {
        if (t[i] == '#' && cnt)
        {
            cnt--;
        }
        else
        {
            if (t[i] != '#')
                cnt = k;
            t1 += t[i];
        }
    }
    if (s1 == t1)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
}

int main()
{
    // FAST;
    int t;
    cin >> t;
    while (t--)
        solve();
}
