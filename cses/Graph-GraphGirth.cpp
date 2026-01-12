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
    ll n, m;
    cin >> n >> m;
    vector<vll> adj(n);
    set<ll> ans;
    rep(i, 0, m)
    {
        ll a, b;
        cin >> a >> b;
        a--, b--;
        adj[a].PB(b);
        adj[b].PB(a);
    }
    rep(i, 0, n)
    {
        queue<ll> q;
        q.push(i);
        vll nodes(n, -1);
        nodes[i] = 0;
        while (!q.empty())
        {
            ll cur = q.front();
            q.pop();
            for (auto &e : adj[cur])
            {
                if (nodes[e] == -1)
                {
                    nodes[e] = nodes[cur] + 1;
                    q.push(e);
                }
                else if (nodes[e] >= nodes[cur])
                {
                    ans.insert(nodes[cur] + nodes[e] + 1);
                }
            }
        }
    }
    if (ans.empty())
        cout << -1 << endl;
    else
        cout << *(ans.begin()) << endl;
}

int main()
{
    FAST;
    // int t;
    // cin >> t;
    // while (t--)
    solve();
}