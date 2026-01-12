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
    string grid[n];
    vector<vll> dir(n, vll(m, 0));
    vector<vll> dist(n, vll(m, INF));
    ll x = -1, y = -1;
    queue<pll> q;
    rep(i, 0, n)
    {
        cin >> grid[i];
        rep(j, 0, m)
        {
            if (grid[i][j] == 'A')
            {
                x = i;
                y = j;
            }
            if (grid[i][j] == 'M')
            {
                q.push({i, j});
                dist[i][j] = 0;
            }
            if (grid[i][j] == '#')
            {
                dist[i][j] = 0;
            }
        }
    }
    ll a, b;
    while (!q.empty())
    {
        pll cur = q.front();
        q.pop();
        rep(i, 0, 4)
        {
            a = cur.F + dx[i], b = cur.S + dy[i];
            if (is_valid(a, b, n, m))
            {
                if (grid[a][b] != '#' && dist[cur.F][cur.S] + 1 < dist[a][b])
                {
                    dist[a][b] = dist[cur.F][cur.S] + 1;
                    q.push({a, b});
                }
            }
        }
    }
    q.push({x, y});
    dir[x][y] = 'A';
    dist[x][y] = 0;
    while (!q.empty())
    {
        pll cur = q.front();
        q.pop();
        rep(i, 0, 4)
        {
            a = cur.F + dx[i], b = cur.S + dy[i];
            if (is_valid(a, b, n, m) && dir[a][b] == 0 && dist[cur.F][cur.S] + 1 < dist[a][b])
            {
                if (i == 0)
                    dir[a][b] = 'R';
                else if (i == 1)
                    dir[a][b] = 'U';
                else if (i == 2)
                    dir[a][b] = 'L';
                else
                    dir[a][b] = 'D';
                dist[a][b] = dist[cur.F][cur.S] + 1;
                q.push({a, b});
            }
            if (!is_valid(a, b, n, m))
            {
                cout << "YES" << endl;
                stack<char> ans;

                a = cur.F, b = cur.S;
                while (dir[a][b] != 'A')
                {
                    ans.push((char)dir[a][b]);
                    if (dir[a][b] == 'R')
                        a -= dx[0], b -= dy[0];
                    else if (dir[a][b] == 'U')
                        a -= dx[1], b -= dy[1];
                    else if (dir[a][b] == 'L')
                        a -= dx[2], b -= dy[2];
                    else if (dir[a][b] == 'D')
                        a -= dx[3], b -= dy[3];
                }
                cout << ans.size() << endl;
                while (!ans.empty())
                {
                    cout << ans.top();
                    ans.pop();
                }
                return;
            }
        }
    }
    cout << "NO" << endl;
}

int main()
{
    FAST;
    // int t;
    // cin >> t;
    // while (t--)
    solve();
}