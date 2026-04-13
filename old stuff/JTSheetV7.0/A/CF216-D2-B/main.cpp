#include <iostream>
#include <vector>

std::vector<std::vector<int>> graph;
std::vector<int> vis;

bool dfs(int cur_node, int par_node, int &nodes_cnt)
{
	if (vis[cur_node])
		return 1;

	vis[cur_node] = 1;

	for (auto child_node : graph[cur_node])
	{
        if (child_node != par_node)
        {
            ++nodes_cnt;

            if (dfs(child_node, cur_node, nodes_cnt) == 1)
                return 1;
        }
	}
	return 0;
}

int main()
{
	int n, m;
	std::cin >> n >> m;
	graph = std::vector<std::vector<int>>(n);
	vis = std::vector<int>(n);
	graph.reserve(n);
	for (int i = 0; i < m; i++)
	{
		int a, b;
		std::cin >> a >> b;
		graph[a - 1].push_back(b - 1);
		graph[b - 1].push_back(a - 1);
	}

	int toRemove = 0;

	for (int i = 0; i < n; i++)
	{
        if (!vis[i])
        {
            int cnt = 0;
            bool solve = dfs(i, -1, cnt);
            if (solve == 1)
                toRemove += (cnt % 2 == 1);
        }
	}

	if ((n - toRemove) % 2 == 1)
		toRemove++;
	std::cout << toRemove;
}
