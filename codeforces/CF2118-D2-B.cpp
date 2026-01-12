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

vll p[64];
ll x[64];

void solve()
{
    ll n;
    cin >> n;
    ll l = 1, r = n;
    cout << max(2 * n - 3, (ll)0) << endl;
    rep(i, 1, n)
    {
        cout << i << ' ' << l << ' ' << r-- << endl;
    }
    l = 2, r = n;
    rrep(i, n, 3)
    {
        cout << i << ' ' << l++ << ' ' << r << endl;
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