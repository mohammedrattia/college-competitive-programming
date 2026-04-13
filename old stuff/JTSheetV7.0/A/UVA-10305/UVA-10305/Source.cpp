#include <iostream>
#include <vector>
#include <cstring>

int n, m;
std::vector<std::vector<int>> adj(150);
std::vector<int> result;
int vis[150];

void dfs(int node)
{
	vis[node] = true;
	for (int i = 0; i < (int)adj[node].size(); i++)
	{
		int child = adj[node][i];
		if (!vis[child])
			dfs(child);
	}
	result.insert(result.begin(), node);
}

int main()
{
	while (std::cin >> n >> m && n != 0)
	{
		adj.clear();
		result.clear();
		adj.resize(n + 1);
		memset(vis, false, sizeof(vis));
		int a, b;
		for (int i = 0; i < m; i++)
		{
			std::cin >> a >> b;
			adj[a].push_back(b);
		}

		for (int i = 1; i <= n; i++)
			if (!vis[i])
				dfs(i);

		for (int i = 0; i < (int)result.size(); i++)
			std::cout << result[i] << " \n"[i == (int)result.size() - 1];

	}
}