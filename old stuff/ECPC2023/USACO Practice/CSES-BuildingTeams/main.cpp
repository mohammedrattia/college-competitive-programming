// CSES - Building Teams (Graph Traversal: BFS)
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int N = 10e5 + 5;

vector<int> adj[N];
bool visited[N];
int flags[N] = {0};
queue<int> q;

int bfs(int cur)
{
    if (visited[cur]) return 0;
    visited[cur] = true;
    flags[cur] = 1;
    q.push(cur);
    while (!q.empty())
    {
        int s = q.front(); q.pop();

        for (auto child : adj[s]) {
            if (visited[child])
            {
                if (flags[child]==flags[s])
                    return -1;
                continue;
            }
            visited[child] = true;
            flags[child] = (flags[s] == 1 ? 2 : 1);
            q.push(child);
        }
    }
    return 0;
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

    for (int i = 1; i <= n; i++)
    {
        if (bfs(i)==-1)
        {
            cout << "IMPOSSIBLE" << endl;
            return 0;
        }
    }

    for (int i = 1; i <= n; i++)
    {
        cout << flags[i] << ' ';
    }
    cout << endl;
}
