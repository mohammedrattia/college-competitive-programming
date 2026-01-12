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

const ll MOD = 1e9 + 7;
const int SZ = 1e6;

// #define endl '\n'

vll p[64];
ll x[64];

void solve()
{
    ll n;
    cin >> n;
    ll num = n, cnt = 0;
    vll arr;
    while (num != 0)
    {
        arr.push_back(num % 10);
        num /= 10;
    }
    ll ans = arr.size() + 1;
    rep(i, 0, 61)
    {
        int j = p[i].size() - 1;
        cnt = arr.size() + p[i].size();
        rrep(k, arr.size() - 1, 0)
        {
            if (arr[k] == p[i][j])
            {
                j--;
                cnt -= 2;
            }
            if (j < 0)
                break;
        }
        // cout << x[i] << endl;
        ans = min(ans, cnt);
    }
    cout << ans << endl;
}

int main()
{
    FAST;
    x[0] = 1;
    rep(i, 0, 61)
    {
        x[i + 1] = x[i] * 2;
        ll num = x[i], cnt = 0;
        while (num != 0)
        {
            p[i].push_back(num % 10);
            num /= 10;
        }
    }
    int t;
    cin >> t;
    while (t--)
        solve();
}