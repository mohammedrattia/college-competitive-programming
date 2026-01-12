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

ll n;
vll adj, vis, ans;
bool is_cycle = false;

int dfs(ll i)
{
    if (ans[i] != -1)
    {
        return ans[i];
    }
    ans[i] = 1 + dfs(adj[i]);
    return ans[i];
}

void floyd(ll x)
{
    ll b = x, a = x;
    do
    {
        if (ans[a] != -2)
            return;
        ans[a] = -1;
        a = adj[a];
        b = adj[adj[b]];
    } while (a != b);
    ll len = 0;
    do
    {
        a = adj[a];
        len++;
    } while (a != b);
    do
    {
        ans[a] = len;
        a = adj[a];
    } while (a != b);
}

void solve()
{
    cin >> n;
    adj = vll(n, 0);
    ans = vll(n, -2);
    rep(i, 0, n)
    {
        cin >> adj[i];
        adj[i]--;
    }
    rep(i, 0, n)
    {
        if (ans[i] == -2)
            floyd(i);
    }
    rep(i, 0, n)
    {
        if (ans[i] == -1)
            dfs(i);
    }
    rep(i, 0, n)
    {
        cout << ans[i] << ' ';
    }
}

int main()
{
    // FAST;
    // int t;
    // cin >> t;
    // while (t--)
    solve();
}