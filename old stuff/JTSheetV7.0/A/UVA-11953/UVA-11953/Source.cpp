#include <iostream>

int n;
char grid[101][101];
bool visited[101][101];
int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { 1, 0, -1, 0 };

bool valid(int r, int c)
{
	return r >= 0 && c >= 0 && r < n && c < n;
}

void dfs(int r, int c)
{
	if (!valid(r, c) || grid[r][c] == '.' || visited[r][c])
		return;

	visited[r][c] = 1;
	for (int i = 0; i < 4; i++)
	{
		dfs(r + dy[i], c + dx[i]);
	}
}

int main()
{
	int t;
	std::cin >> t;
	int c = t;
	while (t--)
	{
		int cnt = 0;
		std::cin >> n;
		for (int i = 0; i < n; i++)
		{
			std::cin >> grid[i];
			for (int j = 0; j < n; j++)
			{
				visited[i][j] = 0;
			}
		}

		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (!visited[i][j] && grid[i][j] == 'x')
				{
					dfs(i, j);
					cnt++;
				}
			}
		}
		std::cout << "Case " << c - t << ": " << cnt << "\n";
	}
}