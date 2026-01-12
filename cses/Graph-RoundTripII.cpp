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

vector<vll> adj;
vll vis;
deque<ll> ans;
set<ll> parents;
bool cycle = false;

void dfs(int i)
{
    vis[i] = true;
    parents.insert(i);
    for (auto &e : adj[i])
    {
        if (vis[e])
        {
            if (parents.count(e))
            {
                cycle = true;
                ans.push_back(e);
                break;
            }
        }
        if (!vis[e])
        {
            dfs(e);
        }
        if (cycle)
            break;
    }
    parents.erase(i);
    if (cycle && (ans.size() < 2 || ans.front() != ans.back()))
        ans.push_back(i);
}

void solve()
{
    ll n, m;
    cin >> n >> m;
    adj = vector<vll>(n);
    vis = vll(n, 0);
    rep(i, 0, m)
    {
        ll a, b;
        cin >> a >> b;
        a--, b--;
        adj[a].PB(b);
    }
    dfs(0);
    if (ans.empty())
    {
        cout << "IMPOSSIBLE" << endl;
        return;
    }
    cout << ans.size() << endl;
    while (!ans.empty())
    {
        cout << ans.back() + 1 << ' ';
        ans.pop_back();
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