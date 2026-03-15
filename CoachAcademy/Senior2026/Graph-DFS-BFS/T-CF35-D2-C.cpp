#include <bits/stdc++.h>

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

void setIO(string s)
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
}

int n, m;

vector<vi> visited;
vector<pii> init;

bool is_valid(int i, int j)
{
    return i > 0 && j > 0 && i <= n && j <= m;
}

int moves[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

pii bfs()
{
    queue<pii> q;
    for (pii &e:init)
    {
        q.push({e.first, e.second});
        visited[e.first][e.second] = 1;
    }

    auto cur = q.front();
    while (!q.empty())
    {
        cur = q.front();
        q.pop();

        for (auto &e:moves)
        {
            int a = cur.first + e[0], b = cur.second + e[1];

            if (is_valid(a, b) && !visited[a][b])
            {
                q.push({a, b});
                visited[a][b] = 1;
            }
        }
    }
    return cur;
}

void solve()
{
    int k;
    cin >> n >> m >> k;

    visited.assign(n+1, vi(m+1, 0));

    int a, b;
    rep(i, 1, k+1)
    {
        cin >> a >> b;
        init.push_back({a, b});
    }

    auto ans = bfs();
    cout << ans.first << ' ' << ans.second;
}

int main()
{
    FAST;
    setIO("");

    solve();
}