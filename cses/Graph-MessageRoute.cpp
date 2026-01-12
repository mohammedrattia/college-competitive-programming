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

bool is_valid(int i, int j, int n, int m) { return i >= 0 && j >= 0 && i < n && i < m; }

vector<vll> adj;
vll parent;
vll dist;

void solve()
{
    ll n, m;
    cin >> n >> m;
    adj = vector<vll>(n);
    parent = vll(n, -1);
    dist = vll(n, 1);
    rep(i, 0, m)
    {
        int a, b;
        cin >> a >> b;
        a--, b--;
        adj[a].PB(b);
        adj[b].PB(a);
    }

    queue<ll> q;
    q.push(0);
    parent[0] = -2;
    while (!q.empty())
    {
        ll cur = q.front();
        q.pop();
        for (auto &e : adj[cur])
        {
            if (parent[e] != -1)
                continue;
            q.push(e);
            dist[e] = dist[cur] + 1;
            parent[e] = cur;
        }
        if (parent[n - 1] != -1)
            break;
    }
    if (parent[n - 1] == -1)
    {
        cout << "IMPOSSIBLE" << endl;
        return;
    }
    cout << dist[n - 1] << endl;
    int e = n - 1;
    stack<ll> ans;
    while (e != -2)
    {
        ans.push(e + 1);
        e = parent[e];
    }
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