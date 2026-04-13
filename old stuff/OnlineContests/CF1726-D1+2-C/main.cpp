#include <bits/stdc++.h>

using namespace std;

#define rep(i, a, b) for(int i = a; i < b; i++)

int visited[200005];
vector<vector<int>> adj;

int dfs(int i)
{
    if (visited[i])
    {
        return 0;
    }
    visited[i] = 1;
    for (auto &e : adj[i])
    {
        dfs(e);
    }
    return 1;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        string str;
        cin >> str;
        adj.clear();
        adj = vector<vector<int>>(2*n+5);
        memset(visited, 0, sizeof(visited));
        int cnt = 0;
        rep(i, 0, 2*n)
        {
            if (str[i] == '(')
            {
                cnt = 0;
                rep(j, 0, 2*n)
                {
                    if (str[j] == '(')
                            cnt++;
                    else cnt--;
                    if (cnt == 0)
                    {
                        adj[i].push_back(j);
                        adj[j].push_back(i);
                    }
                }
            }
        }
        cnt = 0;
        rep(i, 0, n)
            cnt += dfs(i);
        cout << cnt << endl;
    }
}
