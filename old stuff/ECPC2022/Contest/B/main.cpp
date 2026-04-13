#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define rep(i, n) for (int i = 0; i < n; i++)

int N = 2005, M = 5005;
int OO = 1000005;
vector<vector<pair<int,int>>> grid;
vector<int> visited;

int dfs(int node)
{
    if (visited.)
}

int main()
{
    //freopen("insta.in", "r", stdin);
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        grid.reserve(n);
        visited = vector<int>(n, 0);
        int u, v, c;
        rep(i, m)
        {
            cin >> u >> v >> c;
            grid[u].push_back({v, c});
        }
    }
}
