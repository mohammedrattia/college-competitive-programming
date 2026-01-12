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
#define pii pair<int, int>
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

const ll INF = 1e9;
const ll MOD = 1e9 + 7;
const ll iMOD = 998244353;
const int SZ = 1e6;

bool is_valid(int i, int j, int n, int m) { return i < n && i >= 0 && j < m && j >= 0; }

void solve()
{
    ll n;
    cin >> n;
    int arr[n];
    ll dp[1000000 + 1] = {0};
    rep(i, 0, n) cin >> arr[i];

    dp[0] = 1;
    for (auto &c : arr)
    {
        rrep(i, 1000000, 1)
        {
            if (i - c >= 0)
            {
                dp[i] |= dp[i - c];
            }
        }
    }
    ll cnt = 0;
    rep(i, 1, 1000000) cnt += dp[i];
    cout << cnt << endl;
    rep(i, 1, 1000000) if (dp[i] == 1) cout << i << ' ';
}

int main()
{
    FAST;
    // int t;
    // cin >> t;
    // while (t--)
    solve();
}