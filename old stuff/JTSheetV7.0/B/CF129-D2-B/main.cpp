#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<vector<int>> adj(105);
int n, m;

int bfs()
{
    queue<int> q;
    for (int i = 0; i < n; i++)
    {
        if (adj[i+1].size() == 1)
        {
            q.push(i+1);
        }
    }
    int sz;
    int groups = 0;
    bool b;
    while (true)
    {
        sz = q.size();
        b = 0;
        while (sz--)
        {
            int cur = q.front();
            q.pop();

            if (adj[cur].size() != 1)
                continue;
            else
                b = 1;

            int child = adj[cur][0];
            adj[cur].pop_back();
            for (int i = 0; i < adj[child].size(); i++)
            {
                if (adj[child][i] == cur)
                {
                    adj[child].erase(adj[child].begin()+i);
                    break;
                }
            }
            if (adj[child].size() == 1)
                q.push(child);
        }
        if (b)
            groups++;
        if (q.size() == 0)
            break;
    }
    return groups;
}

int main()
{
    cin >> n >> m;
    int a, b;
    while (m--)
    {
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    int num = 0;
    cout << bfs();
}
