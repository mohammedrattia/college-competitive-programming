#include <iostream>
#include <vector>

std::vector<std::vector<int>> adj;
std::vector<int> vis;
std::vector<int> arr;
int n, max_sum;

void dfs(int node, int sum = 0)
{
    if (sum > max_sum)
        max_sum = sum;
    if (vis[node])
        return;
    vis[node] = 1;
    for (int i = 0; i < (int)(adj[node].size()); i++)
    {
        int child = adj[node][i];
        if (!vis[child])
            dfs(child, sum + 1);
    }
}

int main()
{
    long long t;
    std::cin >> t;
    while (t--)
    {
        max_sum = 0;
        adj.clear();
        arr.clear();
        std::cin >> n;
        adj = std::vector<std::vector<int>>(n);
        arr = std::vector<int>(n,0);
        vis = std::vector<int>(n,0);
        for (int i = 0; i < n; i++)
            std::cin >> arr[i];
        for (int i = 0; i < n - 1; i++)
        {
            int x, y;
            std::cin >> x >> y;
            if (arr[x - 1] >= arr[y - 1])
                adj[y - 1].push_back(x - 1);
            if (arr[y - 1] >= arr[x - 1])
                adj[x - 1].push_back(y - 1);
        }
        for (int i = 0; i < n; i++)
        {
            dfs(i);
            vis.clear();
            vis = std::vector<int>(n,0);
        }
        std::cout << max_sum << std::endl;
    }
}
