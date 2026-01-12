#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define vii vector<int>
#define vll vector<ll>
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second

#define rep(i, a, b) for (ll i = (a); i < (b); i++)
#define rrep(i, a, b) for (ll i = (a); i >= (b); i--)

#define all(x) (x).begin(), (x).end()
#define PB push_back
#define MP make_pair
#define sz(x) (int)(x).size()
#define SQ(a) (a) * (a)

#define FAST                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
#define dbg(x) cout << #x << " = " << x << '\n';
#define endl '\n'
#define M_PI 3.14159265358979323846

const ll INF = 1e9;
const ll MOD = 1e9 + 7;
const ll SZ = 1e6;

bool is_valid(int i, int j, int n, int m) { return i >= 0 && j >= 0 && i < n && j < m; }
ll dy[4]{1, 0, -1, 0}, dx[4]{0, -1, 0, 1};

void solve()
{
    ll n;
    cin >> n;
    vll arr(n);
    rep(i, 0, n)
    {
        cin >> arr[i];
    }
    // reverse(arr.begin(), arr.end());
    vll pre(n + 1, 0);
    rep(i, 1, n + 1)
    {
        pre[i] = pre[i - 1] + arr[i - 1];
    }
    vll dp(n, -INF);
    dp[0] = 0;
    rep(i, 1, n)
    {
        if (pre[i] - arr[i] < 0)
            continue;
        ll x = lower_bound(pre.begin(), pre.end(), pre[i] - arr[i]) - pre.begin();
        if (x == n + 1)
            continue;

        dp[i] = dp[x + 1] + 1;
    }
    ll ans = 0;
    rep(i, 0, n)
    {
        if (dp[i] > 0)
            ans += dp[i];
    }
    cout << ans << endl;
}

int main()
{
    FAST;
    // int t;
    // cin >> t;
    // while (t--)
    solve();
}