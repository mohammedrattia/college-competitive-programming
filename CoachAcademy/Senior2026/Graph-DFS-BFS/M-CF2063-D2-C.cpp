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

void dfs(int i)
{
    if (visited[i]) return;
    visited[i] = 1;
    for (auto e:adj[i])
    {
        dfs(e);
    }
}

// SOLVE SPACE
void solve()
{
    // freopen("file.in", "r", stdin);
    // freopen("file.out", "w", stdout);
    ll n;
    cin >> n;
    adj = vector<vll>(n);
    visited = vll(n);
    rep (i, 0, n-1)
    {
        ll a, b;
        cin >> a >> b;
        a--, b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    ll mx = 0;
    rep(i, 0, n)
    {
        if (adj[i].size() >= mx)
        {
            mx = adj[i].size();
        }
    }
    ll cnt = 0;
    vll vals;
    rep(i, 0, n)
    {
        if (adj[i].size() == mx)
        {
            cnt++;
            vals.push_back(i);
        }
    }
    
    if (cnt >= 3)
    {
        cout << 2*mx-1 << endl;
    }
    else if (cnt == 2)
    {
        for (auto e:adj[vals[0]])
        {
            if (e == vals[1])
            {
                cout << 2*mx-2 << endl;
                return;
            }
        }
        cout << 2*mx-1 << endl;
    }
    else
    {
        vll adjacent(n, 0);
        for (auto e:adj[vals[0]])
        {
            adjacent[e]++;
        }
        ll ans = 0;
        rep(i, 0, n)
        {
            if (i == vals[0]) continue;
            ans = max(ans, mx + (ll)adj[i].size() - 1ll - adjacent[i]);
        }
        cout << ans << endl;
    }
}

int main()
{
    // FAST;
    int t;
    cin >> t;
    while (t--)
        solve();
}
