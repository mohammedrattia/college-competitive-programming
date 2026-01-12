#include <bits/stdc++.h>

using namespace std;

#define ll long long

int m;
map<int, vector<int>> adj;
map<int, int> vis;

void dfs(int i)
{
    if (vis[i])
    {
        return;
    }
    vis[i] = 1;
    for (ll e : adj[i])
    {
        dfs(e);
    }
}

int main()
{
    cin >> m;
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    int cnt = 0;
    for (auto &e : adj)
    {
        if (!vis[e.first])
        {
            dfs(e.first);
            cnt++;
        }
    }
    cout << cnt << endl;
}