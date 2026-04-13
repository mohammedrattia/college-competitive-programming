#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int n, m;
int x, y;
string grid[20];
bool visited[25][25] = { 0 };

bool out_grid(int i, int j)
{
    return i >= n || j >= m || i < 0 || j < 0;
}

int solve(int i, int j)
{
    if (visited[i][j])
        return 0;

    visited[i][j] = 1;

    int ret = 1;
    if (!(out_grid(i+1, j)))
        if (grid[i+1][j]=='l')
            ret += solve(i+1, j);
    if (!(out_grid(i, j+1)))
        if (grid[i][j+1]=='l')
            ret += solve(i, j+1);
    if (!(out_grid(i-1, j)))
        if (grid[i-1][j]=='l')
            ret += solve(i-1, j);
    if (!(out_grid(i, j-1)))
        if (grid[i][j-1]=='l')
            ret += solve(i, j-1);
    return ret;
}

int main()
{
    cin >> n >> m;

    for (int i = 0; i < n; i++)
        cin >> grid[i];
    cin >> x >> y;
    int ans = 0;
    solve(x, y);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (grid[i][j]=='l' && !visited[i][j])
                ans = max(ans, solve(i, j));
        }
    }
    cout << ans;
}
