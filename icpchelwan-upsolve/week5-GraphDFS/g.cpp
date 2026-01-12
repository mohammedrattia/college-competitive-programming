#include <bits/stdc++.h>

using namespace std;

#define ll long long

int n;
vector<int> init, goal, flip, ans, vis;
vector<vector<int>> adj;

void dfs(int i, int level, vector<int> f)
{
    if (vis[i])
        return;
    vis[i] = 1;

    if (f[level] == 1)
    {
        init[i] = 1 - init[i];
    }
    if (init[i] != goal[i])
    {
        f[level] = 1 - f[level];
        ans.push_back(i);
    }
    for (int e : adj[i])
    {
        if (!vis[e])
            dfs(e, 1 - level, f);
    }
}

int main()
{
    cin >> n;
    adj = vector<vector<int>>(n);
    init = vector<int>(n);
    goal = vector<int>(n);
    vis = vector<int>(n, 0);
    flip = vector<int>(2, 0);

    for (int i = 0; i < n - 1; i++)
    {
        int a, b;
        cin >> a >> b;
        a--, b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    for (int i = 0; i < n; i++)
    {
        cin >> init[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> goal[i];
    }

    dfs(0, 0, flip);

    cout << ans.size() << endl;
    for (int e : ans)
    {
        cout << e + 1 << endl;
    }
}