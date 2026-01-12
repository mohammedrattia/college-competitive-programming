#include <bits/stdc++.h>

using namespace std;

#define ll long long

int n, m;
vector<vector<int>> adj;
vector<int> teams;

int dfs(int i, int cur = 0)
{
    if (teams[i] == 1 - cur)
        return 1;
    if (teams[i] == cur)
        return 0;
    teams[i] = cur;
    int ret = 0;
    for (ll e : adj[i])
    {
        ret += dfs(e, 1 - cur);
    }
    return ret;
}

int main()
{
    cin >> n >> m;
    adj = vector<vector<int>>(n);
    teams = vector<int>(n, -1);
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        a--, b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    for (int i = 0; i < n; i++)
    {
        if (teams[i] == -1)
            if (dfs(i))
            {
                cout << "IMPOSSIBLE" << endl;
                return 0;
            }
    }
    for (int i = 0; i < n; i++)
    {
        cout << teams[i] + 1 << ' ';
    }
}