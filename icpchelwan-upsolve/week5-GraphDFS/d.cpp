#include <bits/stdc++.h>

using namespace std;

#define ll long long

int n, m;
vector<string> grid;
vector<vector<bool>> vis;

bool is_valid(int i, int j)
{
    return i >= 0 && i < n && j >= 0 && j < m;
}

void dfs(int i, int j)
{
    if (!is_valid(i, j) || grid[i][j] == '#' || vis[i][j])
    {
        return;
    }
    vis[i][j] = 1;
    dfs(i + 1, j);
    dfs(i - 1, j);
    dfs(i, j + 1);
    dfs(i, j - 1);
}

int main()
{
    cin >> n >> m;
    grid = vector<string>(n);
    vis = vector<vector<bool>>(n, vector<bool>(m, 0));
    for (int i = 0; i < n; i++)
    {
        cin >> grid[i];
    }
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (grid[i][j] == '.' && !vis[i][j])
            {
                dfs(i, j);
                cnt++;
            }
        }
    }
    cout << cnt;
}