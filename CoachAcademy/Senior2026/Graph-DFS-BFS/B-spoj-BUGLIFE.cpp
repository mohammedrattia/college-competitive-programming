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

// GRID MOVEMENT
bool is_valid(int i, int j, int n, int m) { return i < n && i >= 0 && j < m && j >= 0; }
int dx[4] = {0, 1, 0, -1};
int dy[4] = {-1, 0, 1, 0};

vector<vll> adj;
vll visited;

int dfs(int i, int last = 0)
{
    if (visited[i])
    {
        if (visited[i] != last+1)
            return 1;
        else return 0;
    }
    visited[i] = last+1;
    
    int ret = 0;
    for (auto e:adj[i])
    {
        ret += dfs(e, 1-last);
    }
    return ret;
}

// SOLVE SPACE
void solve(int t)
{
    // freopen("file.in", "r", stdin);
    // freopen("file.out", "w", stdout);
    cout << "Scenario #" << t << ":" << endl;
    ll n, m;
    cin >> n >> m;
    adj = vector<vll>(n);
    visited = vll(n);
    rep (i, 0, m)
    {
        ll a, b;
        cin >> a >> b;
        a--, b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    rep(i, 0, n)
    {
        if (!visited[i] && dfs(i))
        {
            cout << "Suspicious bugs found!" << endl;
            return;
        }
    }
    cout << "No suspicious bugs found!" << endl;
}

int main()
{
    // FAST;
    int t;
    cin >> t;
    int T = 1;
    while (t--)
        solve(T++);
}