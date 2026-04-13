#include <iostream>
#include <set>
#include <vector>

using namespace std;

vector<int> adj[55];
bool visited[55] = { 0 };

long long dfs(int node)
{
    if (visited[node])
        return 1;
    visited[node] = 1;
    long long ret = 1;
    for (int i = 0; i < adj[node].size(); i++)
    {
        if (!visited[adj[node][i]])
            ret *= dfs(adj[node][i]) * 2;
    }
    return ret;
}

int main()
{
    int n, m;
    cin >> n >> m;
    long long p = 1;
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    for (int i = 1; i <= n; i++)
        p *= dfs(i);
    cout << p;
}
