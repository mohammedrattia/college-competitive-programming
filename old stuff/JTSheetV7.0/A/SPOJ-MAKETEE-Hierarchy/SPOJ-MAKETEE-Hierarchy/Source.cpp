#include <iostream>
#include <vector>

int n, k, w, pos, a;
std::vector<std::vector<int>> adj;
bool vis[100074];
std::vector<int> result;
int parent[100074];

void dfs(int student)
{
	vis[student] = true;
	for (int i = 0; i < (int) adj[student].size(); i++)
	{
		if (!vis[adj[student][i]])
			dfs(adj[student][i]);
	}
	result.push_back(student);
}

int main()
{
	std::cin >> n >> k;

	adj.resize(n + 1);

	for (int i = 1; i <= k; i++)
	{
		std::cin >> w;
		for (int j = 0; j < w; j++)
		{
			std::cin >> a;
			adj[i].push_back(a);
		}
	}

	for (int i = 1; i <= n; i++)
		if (!vis[i])
			dfs(i);

	pos = 0;
	for (int i = n - 1; i < 0; i--)
	{
		parent[result[i]] = pos;
		pos = result[i];
	}

	for (int i = 0; i <= n; i++)
		std::cout << parent[i] << std::endl;
}