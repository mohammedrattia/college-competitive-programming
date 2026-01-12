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
vector<vll> adj_back;
vll vis;
stack<ll> ans;
set<ll> parents;
bool cycle = false;
ll n, m;

void solve()
{
    cin >> n >> m;
    adj = vector<vll>(n);
    adj_back = vector<vll>(n);
    vis = vll(n, 0);
    rep(i, 0, m)
    {
        ll a, b;
        cin >> a >> b;
        a--, b--;
        adj[a].PB(b);
        adj_back[b].PB(a);
    }

    vll in_degree(n);
    rep(i, 0, n)
    {
        for (auto &node : adj[i])
            in_degree[node]++;
    }

    queue<int> q;
    rep(i, 0, n)
    {
        if (in_degree[i] == 0)
        {
            q.push(i);
        }
    }

    vll top_sort;
    while (!q.empty())
    {
        ll cur = q.front();
        q.pop();
        top_sort.push_back(cur);
        for (auto &e : adj[cur])
        {
            if (--in_degree[e] == 0)
            {
                q.push(e);
            }
        }
    }

    vector<pll> dp(n, MP(-INF, -1));
    dp[0].F = 1;
    rep(i, 0, n)
    {
        ll cur = top_sort[i];
        for (auto &e : adj_back[cur])
        {
            if (dp[e].F + 1 > dp[cur].F)
            {
                dp[cur] = {dp[e].F + 1, e};
            }
        }
    }

    if (dp[n - 1].F < 0)
    {
        cout << "IMPOSSIBLE" << endl;
        return;
    }
    ll k = n - 1;
    while (k != -1)
    {
        ans.push(k + 1);
        k = dp[k].S;
    }
    cout << ans.size() << endl;
    while (!ans.empty())
    {
        cout << ans.top() << ' ';
        ans.pop();
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