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
vi ans;
ll n;

int dfs(int i)
{
    if (i >= n)
        return 0;
    int *ret = &ans[i];
    for (auto &e : adj[i])
    {
        *ret += 1 + dfs(e);
    }
    return *ret;
}

void solve()
{
    cin >> n;
    adj = vector<vi>(n);
    ans = vi(n, 0);
    ll x;
    rep(i, 1, n)
    {
        cin >> x;
        adj[x - 1].push_back(i);
    }
    dfs(0);
    rep(i, 0, n)
    {
        cout << ans[i] << ' ';
    }
}

int main()
{
    FAST;
    // int t;
    // cin >> t;
    // while (t--)
    solve();
}