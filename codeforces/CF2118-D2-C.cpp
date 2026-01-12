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
    ll n, k;
    cin >> n >> k;
    int arr[n][64] = {0};
    ll x, ans = 0;
    rep(i, 0, n)
    {
        cin >> x;
        int cur = 0;
        while (x != 0)
        {
            ans += x & 1;
            arr[i][cur++] = x & 1;
            x >>= 1;
        }
    }
    x = 1;
    rep(j, 0, 64)
    {
        rep(i, 0, n)
        {
            if (arr[i][j] != 0)
                continue;
            if (k - x < 0)
            {
                cout << ans << endl;
                return;
            }
            ans++;
            k -= x;
        }
        x <<= 1;
    }
    cout << ans << endl;
}

int main()
{
    FAST;
    int t;
    cin >> t;
    while (t--)
        solve();
}