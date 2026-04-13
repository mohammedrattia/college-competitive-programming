#include <iostream>
#include <vector>

using namespace std;

const int N = 10e5 + 5;

vector<int> adj[N];
bool visited[N];

int dfs(int cur)
{
    if (visited[cur]) return 0;
    visited[cur] = true;
    for (auto child: adj[cur])
    {
        dfs(child);
    }
    return cur;
}

int main()
{
    int n, m;
    cin >> n >> m;

    int y, x;
    for (int i = 0; i < m; i++)
    {
        cin >> y >> x;
        adj[y].push_back(x);
        adj[x].push_back(y);
    }
    vector<int> ans;
    for (int i = 1; i <= n; i++)
    {
        int c = dfs(i);
        if (c!=0)
            ans.push_back(c);
    }
    cout << ans.size()-1 << endl;
    for (int i = 0; i < ans.size()-1; i++)
    {
        cout << ans[i] << ' ' << ans[i+1] << endl;
    }
}
