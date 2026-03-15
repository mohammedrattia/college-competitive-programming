#include <bits/stdc++.h>

using namespace std;

#define rep(a, c, b) for (int a = c; a < b; a++)
#define rrep(a, c, b) for (int a = c; a >= b; a--)

void setIO(string s)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen((s + ".in").c_str(), "r", stdin);
    //freopen((s + ".out").c_str(), "w", stdout);
}

long long n, m;
int ans = 0;

vector<vector<int>> adj;
vector<int> visited;

int dfs(int i)
{
    if (adj[i].empty())
        return 1;

    if (visited[i])
    {
        return visited[i];
    }
    visited[i] = 1;
    int &ret = visited[i];

    for (auto &e:adj[i])
    {
        ret = max(ret, 1 + dfs(e));
    }

    return ret;
}

void solve()
{
    cin >> n;

    visited.assign(n+1, 0);
    adj.clear();
    adj.resize(n+1);

    int a;
    rep(i, 1, n+1)
    {
        cin >> a;
        if (a != -1)
            adj[a].push_back(i);
    }

    for (int i = 1; i <= n; i++)
    {
        if (!visited[i])
        {
            ans = max(ans, dfs(i));
        }
    }
    cout << ans << endl;
}

int main()
{
    setIO("");

    solve();
}