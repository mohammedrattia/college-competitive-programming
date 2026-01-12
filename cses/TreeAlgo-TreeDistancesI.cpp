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
// #define endl '\n'

const ll MOD = 1e9 + 7;
const int SZ = 1e6;

bool is_valid(int i, int j, int n, int m) { return i < n && i >= 0 && j < m && j >= 0; }

vector<vi> adj;
vi cnt1, cnt2;
ll mx = 0, ans = 0;
ll n;

int dfs(int i, int p, vi &ptr, int c = 0)
{
    if (c >= mx)
    {
        ans = i;
        mx = c;
    }

    ptr[i] = c;
    for (auto &e : adj[i])
        if (e != p)
            dfs(e, i, ptr, c + 1);
    return ptr[i];
}

void solve()
{
    cin >> n;
    adj = vector<vi>(n);
    cnt1 = vi(n, 0);
    cnt2 = vi(n, 0);
    ll x, y;
    rep(i, 1, n)
    {
        cin >> x >> y;
        adj[x - 1].push_back(y - 1);
        adj[y - 1].push_back(x - 1);
    }
    dfs(0, -1, cnt1);
    dfs(ans, -1, cnt1);
    dfs(ans, -1, cnt2);
    rep(i, 0, n) cout << max(cnt1[i], cnt2[i]) << ' ';
}

int main()
{
    FAST;
    // int t;
    // cin >> t;
    // while (t--)
    solve();
}